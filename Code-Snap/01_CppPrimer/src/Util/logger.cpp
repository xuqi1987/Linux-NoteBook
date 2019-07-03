//
// Created by xuqi on 2019-07-02.
//

#include "logger.h"

namespace toolkit
{

INSTANCE_IMP(Logger)

LogContextCapturer::LogContextCapturer(Logger &logger, LogLevel level, const char *file, const char *function, int line)
    : _logContext(std::make_shared<LogContext>(level, file, function, line)), _logger(logger)
{

}
LogContextCapturer::LogContextCapturer(const LogContextCapturer &that)
    : _logContext(that._logContext), _logger(that._logger)
{
    const_cast<LogContextPtr &>(that._logContext).reset();
}
LogContextCapturer::~LogContextCapturer()
{
    *this << endl;
}

void LogContextCapturer::clear()
{

}
}
