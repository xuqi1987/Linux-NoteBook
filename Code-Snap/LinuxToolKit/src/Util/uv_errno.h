﻿
#ifndef UV_ERRNO_H_
#define UV_ERRNO_H_

#include <errno.h>

#define UV__EOF     (-4095)
#define UV__UNKNOWN (-4094)

#define UV__EAI_ADDRFAMILY  (-3000)
#define UV__EAI_AGAIN       (-3001)
#define UV__EAI_BADFLAGS    (-3002)
#define UV__EAI_CANCELED    (-3003)
#define UV__EAI_FAIL        (-3004)
#define UV__EAI_FAMILY      (-3005)
#define UV__EAI_MEMORY      (-3006)
#define UV__EAI_NODATA      (-3007)
#define UV__EAI_NONAME      (-3008)
#define UV__EAI_OVERFLOW    (-3009)
#define UV__EAI_SERVICE     (-3010)
#define UV__EAI_SOCKTYPE    (-3011)
#define UV__EAI_BADHINTS    (-3013)
#define UV__EAI_PROTOCOL    (-3014)

/* Only map to the system errno on non-Windows platforms. It's apparently
* a fairly common practice for Windows programmers to redefine errno codes.
*/
#if defined(E2BIG) && !defined(_WIN32)
# define UV__E2BIG (-E2BIG)
#else
# define UV__E2BIG (-4093)
#endif

#if defined(EACCES) && !defined(_WIN32)
# define UV__EACCES (-EACCES)
#else
# define UV__EACCES (-4092)
#endif

#if defined(EADDRINUSE) && !defined(_WIN32)
# define UV__EADDRINUSE (-EADDRINUSE)
#else
# define UV__EADDRINUSE (-4091)
#endif

#if defined(EADDRNOTAVAIL) && !defined(_WIN32)
# define UV__EADDRNOTAVAIL (-EADDRNOTAVAIL)
#else
# define UV__EADDRNOTAVAIL (-4090)
#endif

#if defined(EAFNOSUPPORT) && !defined(_WIN32)
# define UV__EAFNOSUPPORT (-EAFNOSUPPORT)
#else
# define UV__EAFNOSUPPORT (-4089)
#endif

#if defined(EAGAIN) && !defined(_WIN32)
# define UV__EAGAIN (-EAGAIN)
#else
# define UV__EAGAIN (-4088)
#endif

#if defined(EALREADY) && !defined(_WIN32)
# define UV__EALREADY (-EALREADY)
#else
# define UV__EALREADY (-4084)
#endif

#if defined(EBADF) && !defined(_WIN32)
# define UV__EBADF (-EBADF)
#else
# define UV__EBADF (-4083)
#endif

#if defined(EBUSY) && !defined(_WIN32)
# define UV__EBUSY (-EBUSY)
#else
# define UV__EBUSY (-4082)
#endif

#if defined(ECANCELED) && !defined(_WIN32)
# define UV__ECANCELED (-ECANCELED)
#else
# define UV__ECANCELED (-4081)
#endif

#if defined(ECHARSET) && !defined(_WIN32)
# define UV__ECHARSET (-ECHARSET)
#else
# define UV__ECHARSET (-4080)
#endif

#if defined(ECONNABORTED) && !defined(_WIN32)
# define UV__ECONNABORTED (-ECONNABORTED)
#else
# define UV__ECONNABORTED (-4079)
#endif

#if defined(ECONNREFUSED) && !defined(_WIN32)
# define UV__ECONNREFUSED (-ECONNREFUSED)
#else
# define UV__ECONNREFUSED (-4078)
#endif

#if defined(ECONNRESET) && !defined(_WIN32)
# define UV__ECONNRESET (-ECONNRESET)
#else
# define UV__ECONNRESET (-4077)
#endif

#if defined(EDESTADDRREQ) && !defined(_WIN32)
# define UV__EDESTADDRREQ (-EDESTADDRREQ)
#else
# define UV__EDESTADDRREQ (-4076)
#endif

#if defined(EEXIST) && !defined(_WIN32)
# define UV__EEXIST (-EEXIST)
#else
# define UV__EEXIST (-4075)
#endif

#if defined(EFAULT) && !defined(_WIN32)
# define UV__EFAULT (-EFAULT)
#else
# define UV__EFAULT (-4074)
#endif

#if defined(EHOSTUNREACH) && !defined(_WIN32)
# define UV__EHOSTUNREACH (-EHOSTUNREACH)
#else
# define UV__EHOSTUNREACH (-4073)
#endif

#if defined(EINTR) && !defined(_WIN32)
# define UV__EINTR (-EINTR)
#else
# define UV__EINTR (-4072)
#endif

#if defined(EINVAL) && !defined(_WIN32)
# define UV__EINVAL (-EINVAL)
#else
# define UV__EINVAL (-4071)
#endif

#if defined(EIO) && !defined(_WIN32)
# define UV__EIO (-EIO)
#else
# define UV__EIO (-4070)
#endif

#if defined(EISCONN) && !defined(_WIN32)
# define UV__EISCONN (-EISCONN)
#else
# define UV__EISCONN (-4069)
#endif

#if defined(EISDIR) && !defined(_WIN32)
# define UV__EISDIR (-EISDIR)
#else
# define UV__EISDIR (-4068)
#endif

#if defined(ELOOP) && !defined(_WIN32)
# define UV__ELOOP (-ELOOP)
#else
# define UV__ELOOP (-4067)
#endif

#if defined(EMFILE) && !defined(_WIN32)
# define UV__EMFILE (-EMFILE)
#else
# define UV__EMFILE (-4066)
#endif

#if defined(EMSGSIZE) && !defined(_WIN32)
# define UV__EMSGSIZE (-EMSGSIZE)
#else
# define UV__EMSGSIZE (-4065)
#endif

#if defined(ENAMETOOLONG) && !defined(_WIN32)
# define UV__ENAMETOOLONG (-ENAMETOOLONG)
#else
# define UV__ENAMETOOLONG (-4064)
#endif

#if defined(ENETDOWN) && !defined(_WIN32)
# define UV__ENETDOWN (-ENETDOWN)
#else
# define UV__ENETDOWN (-4063)
#endif

#if defined(ENETUNREACH) && !defined(_WIN32)
# define UV__ENETUNREACH (-ENETUNREACH)
#else
# define UV__ENETUNREACH (-4062)
#endif

#if defined(ENFILE) && !defined(_WIN32)
# define UV__ENFILE (-ENFILE)
#else
# define UV__ENFILE (-4061)
#endif

#if defined(ENOBUFS) && !defined(_WIN32)
# define UV__ENOBUFS (-ENOBUFS)
#else
# define UV__ENOBUFS (-4060)
#endif

#if defined(ENODEV) && !defined(_WIN32)
# define UV__ENODEV (-ENODEV)
#else
# define UV__ENODEV (-4059)
#endif

#if defined(ENOENT) && !defined(_WIN32)
# define UV__ENOENT (-ENOENT)
#else
# define UV__ENOENT (-4058)
#endif

#if defined(ENOMEM) && !defined(_WIN32)
# define UV__ENOMEM (-ENOMEM)
#else
# define UV__ENOMEM (-4057)
#endif

#if defined(ENONET) && !defined(_WIN32)
# define UV__ENONET (-ENONET)
#else
# define UV__ENONET (-4056)
#endif

#if defined(ENOSPC) && !defined(_WIN32)
# define UV__ENOSPC (-ENOSPC)
#else
# define UV__ENOSPC (-4055)
#endif

#if defined(ENOSYS) && !defined(_WIN32)
# define UV__ENOSYS (-ENOSYS)
#else
# define UV__ENOSYS (-4054)
#endif

#if defined(ENOTCONN) && !defined(_WIN32)
# define UV__ENOTCONN (-ENOTCONN)
#else
# define UV__ENOTCONN (-4053)
#endif

#if defined(ENOTDIR) && !defined(_WIN32)
# define UV__ENOTDIR (-ENOTDIR)
#else
# define UV__ENOTDIR (-4052)
#endif

#if defined(ENOTEMPTY) && !defined(_WIN32)
# define UV__ENOTEMPTY (-ENOTEMPTY)
#else
# define UV__ENOTEMPTY (-4051)
#endif

#if defined(ENOTSOCK) && !defined(_WIN32)
# define UV__ENOTSOCK (-ENOTSOCK)
#else
# define UV__ENOTSOCK (-4050)
#endif

#if defined(ENOTSUP) && !defined(_WIN32)
# define UV__ENOTSUP (-ENOTSUP)
#else
# define UV__ENOTSUP (-4049)
#endif

#if defined(EPERM) && !defined(_WIN32)
# define UV__EPERM (-EPERM)
#else
# define UV__EPERM (-4048)
#endif

#if defined(EPIPE) && !defined(_WIN32)
# define UV__EPIPE (-EPIPE)
#else
# define UV__EPIPE (-4047)
#endif

#if defined(EPROTO) && !defined(_WIN32)
# define UV__EPROTO (-EPROTO)
#else
# define UV__EPROTO (-4046)
#endif

#if defined(EPROTONOSUPPORT) && !defined(_WIN32)
# define UV__EPROTONOSUPPORT (-EPROTONOSUPPORT)
#else
# define UV__EPROTONOSUPPORT (-4045)
#endif

#if defined(EPROTOTYPE) && !defined(_WIN32)
# define UV__EPROTOTYPE (-EPROTOTYPE)
#else
# define UV__EPROTOTYPE (-4044)
#endif

#if defined(EROFS) && !defined(_WIN32)
# define UV__EROFS (-EROFS)
#else
# define UV__EROFS (-4043)
#endif

#if defined(ESHUTDOWN) && !defined(_WIN32)
# define UV__ESHUTDOWN (-ESHUTDOWN)
#else
# define UV__ESHUTDOWN (-4042)
#endif

#if defined(ESPIPE) && !defined(_WIN32)
# define UV__ESPIPE (-ESPIPE)
#else
# define UV__ESPIPE (-4041)
#endif

#if defined(ESRCH) && !defined(_WIN32)
# define UV__ESRCH (-ESRCH)
#else
# define UV__ESRCH (-4040)
#endif

#if defined(ETIMEDOUT) && !defined(_WIN32)
# define UV__ETIMEDOUT (-ETIMEDOUT)
#else
# define UV__ETIMEDOUT (-4039)
#endif

#if defined(ETXTBSY) && !defined(_WIN32)
# define UV__ETXTBSY (-ETXTBSY)
#else
# define UV__ETXTBSY (-4038)
#endif

#if defined(EXDEV) && !defined(_WIN32)
# define UV__EXDEV (-EXDEV)
#else
# define UV__EXDEV (-4037)
#endif

#if defined(EFBIG) && !defined(_WIN32)
# define UV__EFBIG (-EFBIG)
#else
# define UV__EFBIG (-4036)
#endif

#if defined(ENOPROTOOPT) && !defined(_WIN32)
# define UV__ENOPROTOOPT (-ENOPROTOOPT)
#else
# define UV__ENOPROTOOPT (-4035)
#endif

#if defined(ERANGE) && !defined(_WIN32)
# define UV__ERANGE (-ERANGE)
#else
# define UV__ERANGE (-4034)
#endif

#if defined(ENXIO) && !defined(_WIN32)
# define UV__ENXIO (-ENXIO)
#else
# define UV__ENXIO (-4033)
#endif

#if defined(EMLINK) && !defined(_WIN32)
# define UV__EMLINK (-EMLINK)
#else
# define UV__EMLINK (-4032)
#endif

/* EHOSTDOWN is not visible on BSD-like systems when _POSIX_C_SOURCE is
* defined. Fortunately, its value is always 64 so it's possible albeit
* icky to hard-code it.
*/
#if defined(EHOSTDOWN) && !defined(_WIN32)
# define UV__EHOSTDOWN (-EHOSTDOWN)
#elif defined(__APPLE__) || \
      defined(__DragonFly__) || \
      defined(__FreeBSD__) || \
      defined(__FreeBSD_kernel__) || \
      defined(__NetBSD__) || \
      defined(__OpenBSD__)
# define UV__EHOSTDOWN (-64)
#else
# define UV__EHOSTDOWN (-4031)
#endif

#if defined(EREMOTEIO) && !defined(_WIN32)
# define UV__EREMOTEIO (-EREMOTEIO)
#else
# define UV__EREMOTEIO (-4030)
#endif


#define UV_ERRNO_MAP(XX)                                                      \
  XX(E2BIG, "argument list too long")                                         \
  XX(EACCES, "permission denied")                                             \
  XX(EADDRINUSE, "address already in use")                                    \
  XX(EADDRNOTAVAIL, "address not available")                                  \
  XX(EAFNOSUPPORT, "address family not supported")                            \
  XX(EAGAIN, "resource temporarily unavailable")                              \
  XX(EAI_ADDRFAMILY, "address family not supported")                          \
  XX(EAI_AGAIN, "temporary failure")                                          \
  XX(EAI_BADFLAGS, "bad ai_flags value")                                      \
  XX(EAI_BADHINTS, "invalid value for hints")                                 \
  XX(EAI_CANCELED, "request canceled")                                        \
  XX(EAI_FAIL, "permanent failure")                                           \
  XX(EAI_FAMILY, "ai_family not supported")                                   \
  XX(EAI_MEMORY, "out of memory")                                             \
  XX(EAI_NODATA, "no address")                                                \
  XX(EAI_NONAME, "unknown node or service")                                   \
  XX(EAI_OVERFLOW, "argument buffer overflow")                                \
  XX(EAI_PROTOCOL, "resolved protocol is unknown")                            \
  XX(EAI_SERVICE, "service not available for socket type")                    \
  XX(EAI_SOCKTYPE, "socket type not supported")                               \
  XX(EALREADY, "connection already in progress")                              \
  XX(EBADF, "bad file descriptor")                                            \
  XX(EBUSY, "resource busy or locked")                                        \
  XX(ECANCELED, "operation canceled")                                         \
  XX(ECHARSET, "invalid Unicode character")                                   \
  XX(ECONNABORTED, "software caused connection abort")                        \
  XX(ECONNREFUSED, "connection refused")                                      \
  XX(ECONNRESET, "connection reset by peer")                                  \
  XX(EDESTADDRREQ, "destination address required")                            \
  XX(EEXIST, "file already exists")                                           \
  XX(EFAULT, "bad address in system call argument")                           \
  XX(EFBIG, "file too large")                                                 \
  XX(EHOSTUNREACH, "host is unreachable")                                     \
  XX(EINTR, "interrupted system call")                                        \
  XX(EINVAL, "invalid argument")                                              \
  XX(EIO, "i/o error")                                                        \
  XX(EISCONN, "socket is already connected")                                  \
  XX(EISDIR, "illegal operation on a directory")                              \
  XX(ELOOP, "too many symbolic links encountered")                            \
  XX(EMFILE, "too many open files")                                           \
  XX(EMSGSIZE, "message too long")                                            \
  XX(ENAMETOOLONG, "name too long")                                           \
  XX(ENETDOWN, "network is down")                                             \
  XX(ENETUNREACH, "network is unreachable")                                   \
  XX(ENFILE, "file table overflow")                                           \
  XX(ENOBUFS, "no buffer space available")                                    \
  XX(ENODEV, "no such device")                                                \
  XX(ENOENT, "no such file or directory")                                     \
  XX(ENOMEM, "not enough memory")                                             \
  XX(ENONET, "machine is not on the network")                                 \
  XX(ENOPROTOOPT, "protocol not available")                                   \
  XX(ENOSPC, "no space left on device")                                       \
  XX(ENOSYS, "function not implemented")                                      \
  XX(ENOTCONN, "socket is not connected")                                     \
  XX(ENOTDIR, "not a directory")                                              \
  XX(ENOTEMPTY, "directory not empty")                                        \
  XX(ENOTSOCK, "socket operation on non-socket")                              \
  XX(ENOTSUP, "operation not supported on socket")                            \
  XX(EPERM, "operation not permitted")                                        \
  XX(EPIPE, "broken pipe")                                                    \
  XX(EPROTO, "protocol error")                                                \
  XX(EPROTONOSUPPORT, "protocol not supported")                               \
  XX(EPROTOTYPE, "protocol wrong type for socket")                            \
  XX(ERANGE, "result too large")                                              \
  XX(EROFS, "read-only file system")                                          \
  XX(ESHUTDOWN, "cannot send after transport endpoint shutdown")              \
  XX(ESPIPE, "invalid seek")                                                  \
  XX(ESRCH, "no such process")                                                \
  XX(ETIMEDOUT, "connection timed out")                                       \
  XX(ETXTBSY, "text file is busy")                                            \
  XX(EXDEV, "cross-device link not permitted")                                \
  XX(UNKNOWN, "unknown error")                                                \
  XX(EOF, "end of file")                                                      \
  XX(ENXIO, "no such device or address")                                      \
  XX(EMLINK, "too many links")                                                \
  XX(EHOSTDOWN, "host is down")                                               \
  XX(EREMOTEIO, "remote I/O error")                                           \

typedef enum {
#define XX(code, _) UV_ ## code = UV__ ## code,
	UV_ERRNO_MAP(XX)
#undef XX
	UV_ERRNO_MAX = UV__EOF - 1
} uv_errno_t;


const char* uv_err_name(int err);
const char* uv_strerror(int err);

int uv_translate_posix_error(int err);
//netErr参数在windows平台下才有效
int get_uv_error(bool netErr = true);
//netErr参数在windows平台下才有效
const char* get_uv_errmsg(bool netErr = true);



#endif /* UV_ERRNO_H_ */