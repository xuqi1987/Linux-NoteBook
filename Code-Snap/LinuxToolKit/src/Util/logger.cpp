//
// Created by xuqi on 2019-07-02.
//

#include "logger.h"
#include <syslog.h>

namespace toolkit {

#define CLEAR_COLOR "\033[0m"
static const char *LOG_CONST_TABLE[][3] = {
    {"\033[44;37m", "\033[34m", "T"},
    {"\033[42;37m", "\033[32m", "D"},
    {"\033[46;37m", "\033[36m", "I"},
    {"\033[43;37m", "\033[33m", "W"},
    {"\033[41;37m", "\033[31m", "E"}};

INSTANCE_IMP(Logger, string("Logger"))

void LogChannel::format(const Logger &logger,
                        ostream &ost,
                        const LogContextPtr &logContext,
                        bool enableColor,
                        bool enableDetail) {
  if (!enableDetail && logContext->str().empty()) {
    //没有任何信息打印
    return;
  }

  if (enableDetail) {
    ost << logger.getName() << "(" << getpid() << ") " << logContext->m_pFile << " " << logContext->m_line << endl;
  }

  if (enableColor) {
    ost << LOG_CONST_TABLE[logContext->m_level][1];
  }

  ost << printTime(logContext->_tv) << " " << LOG_CONST_TABLE[logContext->m_level][2] << " | ";

  if (enableDetail) {
    ost << logContext->m_pFunction << " ";
  }

  ost << logContext->str();

  if (enableColor) {
    ost << CLEAR_COLOR;
  }

  ost << endl;

}
void ConsoleChannel::write(const Logger &logger, const LogContextPtr &logContext) {
  if (m_level > logContext->m_level) {
    return;
  }

  format(logger, std::cout, logContext, true, true);

}

void FileChannel::write(const Logger &logger, const LogContextPtr &logContext) {
  if (m_level > logContext->m_level) {
    return;
  }
  if (!m_fstream.is_open()) {
    open();
  }
  format(logger, m_fstream, logContext, false);
}

void FileChannel::open() {
  // Ensure a path was set
  if (m_path.empty()) {
    throw runtime_error("Log file path must be set.");
  }
  // Open the file stream
  m_fstream.close();
  m_fstream.open(m_path.c_str(), ios::out | ios::app);
  // Throw on failure
  if (!m_fstream.is_open()) {
    throw runtime_error("Failed to open log file: " + m_path);
  }
}
void FileChannel::close() {
  m_fstream.close();
}

void SysLogChannel::write(const Logger &logger, const LogContextPtr &logContext) {
  if (m_level > logContext->m_level) {
    return;
  }
  static int s_syslog_lev[10];

  s_syslog_lev[LTrace] = LOG_DEBUG;
  s_syslog_lev[LDebug] = LOG_INFO;
  s_syslog_lev[LInfo] = LOG_NOTICE;
  s_syslog_lev[LWarn] = LOG_WARNING;
  s_syslog_lev[LError] = LOG_ERR;


  syslog(s_syslog_lev[logContext->m_level],"-> %s %d\r\n",logContext->m_pFile,logContext->m_line);
  syslog(s_syslog_lev[logContext->m_level], "## %s %s | %s %s\r\n", printTime(logContext->_tv).data(),
         LOG_CONST_TABLE[logContext->m_level][2], logContext->m_pFunction, logContext->str().c_str());
}
}
