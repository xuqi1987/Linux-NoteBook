//
// Created by xuqi on 2019-07-02.
//

#ifndef LOGGER_H
#define LOGGER_H

#include <sys/time.h>
#include <stdio.h>
#include <string.h>
#include <map>
#include <deque>
#include <iostream>
#include <fstream>
#include <sstream>
#include <thread>
#include <memory>
#include <mutex>

#include <sys/types.h>
#include <unistd.h>

#include "util.h"

namespace toolkit {

class LogContext;

class LogChannel;

class LogWriter;

class Logger;

typedef std::shared_ptr<LogContext> LogContextPtr;

typedef enum {
  LTrace = 0, LDebug, LInfo, LWarn, LError
} LogLevel;

class LogChannel : public noncopyable {
 public:
  LogChannel(const string &name, LogLevel level = LTrace)
      : m_name(name), m_level(level) {

  }

  virtual ~LogChannel() {

  }

  virtual void write(const Logger &logger, const LogContextPtr &stream) = 0;

  const string &name() const { return m_name; };

  void setLevel(LogLevel level) { m_level = level; };

  static std::string printTime(const timeval &tv) {
    time_t sec_tmp = tv.tv_sec;
    struct tm *tm = localtime(&sec_tmp);
    char buf[128];
    snprintf(buf, sizeof(buf), "%d-%02d-%02d %02d:%02d:%02d.%03d",
             1900 + tm->tm_year,
             1 + tm->tm_mon,
             tm->tm_mday,
             tm->tm_hour,
             tm->tm_min,
             tm->tm_sec,
             (int) (tv.tv_usec / 1000));
    return buf;
  }

 protected:

  virtual void format(const Logger &logger,
                      ostream &ost,
                      const LogContextPtr &logContext,
                      bool enableColor = true,
                      bool enableDetail = true);

 protected:
  string m_name;
  LogLevel m_level; // 每个Channel都有自己的等级
};

/**
 *  Log的内容
 */
class LogContext : public ostringstream {
 public:
  friend class LogContextCapturer;

 public:
  LogLevel m_level;
  int m_line;
  const char *m_pFile;
  const char *m_pFunction;
  struct timeval _tv;
 private:
  LogContext(LogLevel level, const char *file, const char *function, int line)
      : m_level(level),
        m_line(line),
        m_pFile(file),
        m_pFunction(function) {
    gettimeofday(&_tv, NULL);
  }
};

/**
 * 写日志器
 */
class LogWriter : public noncopyable {
 public:
  LogWriter() {}
  virtual ~LogWriter() {}
  virtual void write(const LogContextPtr &stream) = 0;
};



/**
 * 每个Logger对象有一个Channel Map 和writer
 * 如果writer为空，则写入channles，否则写入writer
 */
class Logger : public std::enable_shared_from_this<Logger>, public noncopyable {
 public:

  friend class LogContextCapturer;

  typedef std::shared_ptr<Logger> Ptr;

  static Logger &Instance();

  Logger(const string &loggerName) { m_loggerName = loggerName; };

  ~Logger() {};

  void add(const std::shared_ptr<LogChannel> &channel) {
    m_ChannelsPoint[channel->name()] = channel;
  }

  void del(const string &name) {
    m_ChannelsPoint.erase(name);
  }

  std::shared_ptr<LogChannel> get(const string &name) {
    auto it = m_ChannelsPoint.find(name);
    if (it == m_ChannelsPoint.end()) {
      return nullptr;
    }
    return it->second;
  }

  void setWriter(const std::shared_ptr<LogWriter> &writer) {
    m_pWriter = writer;
  }

  void setLevel(LogLevel level) {
    for (auto &ch : m_ChannelsPoint) {
      ch.second->setLevel(level);
    }
  }

  const string &getName() const {
    return m_loggerName;
  }

 private:

  void writeChannels(const LogContextPtr &stream) {
    for (auto &c : m_ChannelsPoint) {
      c.second->write(*this, stream);
    }
  }

  void write(const LogContextPtr &stream) {
    if (m_pWriter) {
      m_pWriter->write(stream);
    } else {
      writeChannels(stream);
    }
  }

  map<string, std::shared_ptr<LogChannel> > m_ChannelsPoint;
  std::shared_ptr<LogWriter> m_pWriter;
  string m_loggerName;
};

/**
 *  可以有多个Capturer，每个Capture可以logContext，他们使用同一个logger用于输出Log
 */
class LogContextCapturer : public noncopyable { //禁止拷贝构造函数
 public:
  LogContextCapturer(Logger &logger, LogLevel level, const char *file, const char *function, int line)
      : m_pLogContext(new LogContext(level, file, function, line)), m_logger(logger) {}

  LogContextCapturer(const LogContextCapturer &that) // 复制一个LogContextCapturer时，需要清空当前的log
      : m_pLogContext(that.m_pLogContext), m_logger(that.m_logger) {
    const_cast<LogContextPtr &>(that.m_pLogContext).reset();
  }

  ~LogContextCapturer() { *this << endl; }

  LogContextCapturer &operator<<(ostream &(*f)(ostream &)) {

    if (!m_pLogContext) {
      return *this;
    }
    m_logger.write(m_pLogContext); // 将LogContext 的内容传给Logger，并通过Logger传给不同的channel或者writter
    m_pLogContext.reset(); // 清空log的内容
    return *this;
  }

  template<typename T>
  LogContextCapturer &operator<<(T &&data) {

    if (!m_pLogContext) {
      return *this;
    }
    (*m_pLogContext) << std::forward<T>(data); // 将log存到自己的logContext中

    return *this;
  }

  void clear() { m_pLogContext.reset(); }

 private:
  LogContextPtr m_pLogContext; // 用于保存log的内容
  Logger &m_logger; // Log对象的输出
};

class AsyncLogWriter : public LogWriter {
  /*
public:
  AsyncLogWriter(Logger &logger = Logger::Inst());
  ~AsyncLogWriter();
private:
  void run();
  void flushAll();
  void write(const LogContextPtr &stream) override;
private:
  bool _exit_flag;
  std::shared_ptr<thread> _thread;
  List<LogContextPtr> _pending;
  semaphore _sem;
  mutex _mutex;
  Logger &m_logger;

   */
};

class ConsoleChannel : public LogChannel {
 public:
  ConsoleChannel(const string &name = "ConsoleChannel", LogLevel level = LTrace) : LogChannel(name, level) {};
  ~ConsoleChannel() {};
  void write(const Logger &logger, const LogContextPtr &logContext) override;

};

/**
 * 输出日志至文件
 */
class FileChannel : public LogChannel {
 public:
  FileChannel(const string &name = "FileChannel", const string &path = exePath() + ".log", LogLevel level = LTrace)
      : LogChannel(name, level), m_path(path) {};
  ~FileChannel() {};

  void write(const Logger &logger, const std::shared_ptr<LogContext> &logContext) override;
  void setPath(const string &path) {
    m_path = path;
    open();
  };
  const string &path() const { return m_path; };

 protected:
  virtual void open();
  virtual void close();
 protected:
  ofstream m_fstream;
  string m_path;

};

class SysLogChannel : public LogChannel {
 public:
  SysLogChannel(const string &name = "SysLogChannel", LogLevel level = LTrace) : LogChannel(name, level) {};
  ~SysLogChannel() {};
  void write(const Logger &logger, const LogContextPtr &logContext) override;
};


#define TraceL LogContextCapturer(Logger::Instance(), LTrace, __FILE__,__FUNCTION__, __LINE__)
#define DebugL LogContextCapturer(Logger::Instance(),LDebug, __FILE__,__FUNCTION__, __LINE__)
#define InfoL LogContextCapturer(Logger::Instance(),LInfo, __FILE__,__FUNCTION__, __LINE__)
#define WarnL LogContextCapturer(Logger::Instance(),LWarn,__FILE__, __FUNCTION__, __LINE__)
#define ErrorL LogContextCapturer(Logger::Instance(),LError,__FILE__, __FUNCTION__, __LINE__)
#define WriteL(level) LogContextCapturer(Logger::Instance(),level,__FILE__, __FUNCTION__, __LINE__)

}

#endif //LOGGER_H
