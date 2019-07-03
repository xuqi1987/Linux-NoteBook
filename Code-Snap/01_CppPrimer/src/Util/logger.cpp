//
// Created by xuqi on 2019-07-02.
//

#include "logger.h"

namespace toolkit
{

#define CLEAR_COLOR "\033[0m"
static const char *LOG_CONST_TABLE[][3] = {
    {"\033[44;37m", "\033[34m" , "T"},
    {"\033[42;37m", "\033[32m" , "D"},
    {"\033[46;37m", "\033[36m" , "I"},
    {"\033[43;37m", "\033[33m" , "W"},
    {"\033[41;37m", "\033[31m" , "E"}};

INSTANCE_IMP(Logger,string("Logger"))

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

  format(logger,std::cout,logContext, true,true);

}
void FileChannel::write(const Logger &logger, const LogContextPtr &stream) {

}
}
