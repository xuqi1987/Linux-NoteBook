
#include "uv_errno.h"
#include <stdio.h>
#include <stdlib.h>

#include <errno.h>


static const char *uv__unknown_err_code(int err)
{
    static char buf[32];
    snprintf(buf, sizeof(buf), "Unknown system error %d", err);
    return buf;
}

#define UV_ERR_NAME_GEN(name, _) case UV_ ## name: return #name;
const char *uv_err_name(int err)
{
    switch (err) {
        UV_ERRNO_MAP(UV_ERR_NAME_GEN)
    }
    return uv__unknown_err_code(err);
}
#undef UV_ERR_NAME_GEN


#define UV_STRERROR_GEN(name, msg) case UV_ ## name: return msg;
const char *uv_strerror(int err)
{
    switch (err) {
        UV_ERRNO_MAP(UV_STRERROR_GEN)
    }
    return uv__unknown_err_code(err);
}
#undef UV_STRERROR_GEN


int uv_translate_posix_error(int err)
{
    if (err <= 0) {
        return err;
    }
    switch (err) {
        //为了兼容windows/unix平台，信号EINPROGRESS ，EAGAIN，EWOULDBLOCK，ENOBUFS 全部统一成EAGAIN处理
        case ENOBUFS://在mac系统下实测发现会有此信号发生
        case EINPROGRESS:
        case EWOULDBLOCK: err = EAGAIN;
            break;
        default: break;
    }
    return -err;
}

int get_uv_error(bool netErr)
{
    return uv_translate_posix_error(errno);
}

const char *get_uv_errmsg(bool netErr)
{
    return uv_strerror(get_uv_error(netErr));
}
