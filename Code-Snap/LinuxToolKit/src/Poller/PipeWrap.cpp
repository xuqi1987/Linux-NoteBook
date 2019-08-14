
#include <stdexcept>
#include "PipeWrap.h"
#include "Util/util.h"
#include "Util/uv_errno.h"
#include "Network/sockutil.h"

using namespace std;

#define checkFD(fd) \
    if (fd == -1) { \
        clearFD(); \
        throw runtime_error(StrPrinter << "create windows pipe failed:" << get_uv_errmsg());\
    }

#define closeFD(fd) \
    if (fd != -1) { \
        close(fd);\
        fd = -1;\
    }

namespace toolkit
{

PipeWrap::PipeWrap()
{
    // 打开管道
    if (pipe(_pipe_fd) == -1) {
        throw runtime_error(StrPrinter << "create posix pipe failed:" << get_uv_errmsg());\

    }

    // 设置读管道为非block
    SockUtil::setNoBlocked(_pipe_fd[0], true);
    // 设置写管道为block，如果满了，则阻塞
    SockUtil::setNoBlocked(_pipe_fd[1], false);
}

void PipeWrap::clearFD()
{
    closeFD(_pipe_fd[0]);
    closeFD(_pipe_fd[1]);
}

PipeWrap::~PipeWrap()
{
    clearFD();
}

int PipeWrap::write(const void *buf, int n)
{
    int ret;
    do {
        ret = ::write(_pipe_fd[1], buf, n);
    }
    while (-1 == ret && UV_EINTR == get_uv_error(true));
    return ret;
}

int PipeWrap::read(void *buf, int n)
{
    int ret;
    do {
        ret = ::read(_pipe_fd[0], buf, n);
    }
    while (-1 == ret && UV_EINTR == get_uv_error(true));
    return ret;
}

} /* namespace toolkit*/
