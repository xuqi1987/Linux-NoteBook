//
// Created by xuqi on 2019-07-02.
//

#ifndef LOGGER_H
#define LOGGER_H

#include <memory>
#include <map>
#include <iostream>
#include "util.h"


namespace toolkit
{

class LogContext;
class LogChannel;
class LogWriter;

typedef std::shared_ptr<LogContext> LogContextPtr;

typedef enum
{
    LTrace = 0, LDebug, LInfo, LWarn, LError
} LogLevel;

class Logger: public std::enable_shared_from_this<Logger>, public noncopyable
{
public:
    friend class AsyncLogWriter;
    friend class LogContextCapturer;
    typedef std::shared_ptr<Logger> Ptr;

    static Logger &Inst();


    Logger(const string &loggerName);
    ~Logger();

    void add(const std::shared_ptr<LogChannel> &channel){
        _channels[channel->name()] = channel;
    }

    void del(const string &name) {
        _channels.erase(name);
    }

    std::shared_ptr<LogChannel> get(const string &name) {
        auto it = _channels.find(name);
        if (it == _channels.end()){
            return nullptr;
        }
        return it->second;
    }

    void setWriter(const std::shared_ptr<LogWriter> &writer) {
        _writer = writer;
    }

    void setLevel(LogLevel level) {

    }

    const string &getName() const {

    }

private:
    void writeChannels(const LogContextPtr &stream);
    void write(const LogContextPtr &stream);

    map<string, std::shared_ptr<LogChannel> > _channels;
    std::shared_ptr<LogWriter> _writer;
    string _loggerName;
};

class LogContext: public ostringstream
{
public:
    friend class LogContextCapturer;
public:
    LogLevel _level;
    int _line;
    const char *_file;
    const char *_function;
    struct timeval _tv;
private:
    LogContext(LogLevel level, const char *file, const char *function, int line);
};

class LogContextCapturer: public std::enable_shared_from_this<LogContextCapturer>, public noncopyable
{
public:
    LogContextCapturer(Logger &logger, LogLevel level, const char *file, const char *function, int line);
    LogContextCapturer(const LogContextCapturer &that);
    ~LogContextCapturer();
    LogContextCapturer &operator<<(ostream &(*f)(ostream &))
    {
        if (!_logContext) {
            return *this;
        }
        _logger.write(_logContext);
        _logContext.reset();
        return *this;

    }

    template<typename T>
    LogContextCapturer &operator<<(T &&data)
    {
        if (!_logContext) {
            return *this;
        }
        (*_logContext) << std::forward<T>(data);
        return *this;
    }

    void clear();
private:
    LogContextPtr _logContext;
    Logger &_logger;
};

class LogWriter: public std::enable_shared_from_this<LogWriter>, public noncopyable
{

};

class AsyncLogWriter: public LogWriter
{

};

class LogChannel: public noncopyable
{
public:
    LogChannel(const string& name, LogLevel level = LTrace);
    virtual ~LogChannel();
    virtual void write(const Logger &logger,const LogContextPtr & stream) = 0;
    const string &name() const ;
    void setLevel(LogLevel level);

    static std::string printTime(const timeval &tv);
protected:
    /**
    * 打印日志至输出流
    * @param ost 输出流
    * @param enableColor 是否请用颜色
    * @param enableDetail 是否打印细节(函数名、源码文件名、源码行)
    */
    virtual void format(const Logger &logger,
                        ostream &ost,
                        const LogContextPtr & stream,
                        bool enableColor = true,
                        bool enableDetail = true);
protected:
    string _name;
    LogLevel _level;
};

class ConsoleChannel: public LogChannel
{

};

class FileChannel: public LogChannel
{

};

#define TraceL LogContextCapturer(Logger::Inst(), LTrace, __FILE__,__FUNCTION__, __LINE__)
#define DebugL LogContextCapturer(Logger::Inst(),LDebug, __FILE__,__FUNCTION__, __LINE__)
#define InfoL LogContextCapturer(Logger::Inst(),LInfo, __FILE__,__FUNCTION__, __LINE__)
#define WarnL LogContextCapturer(Logger::Inst(),LWarn,__FILE__, __FUNCTION__, __LINE__)
#define ErrorL LogContextCapturer(Logger::Inst(),LError,__FILE__, __FUNCTION__, __LINE__)
#define WriteL(level) LogContextCapturer(Logger::Inst(),level,__FILE__, __FUNCTION__, __LINE__)

}

#endif //LOGGER_H
