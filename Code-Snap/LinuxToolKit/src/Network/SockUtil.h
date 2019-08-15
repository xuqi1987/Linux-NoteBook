
#ifndef NETWORK_SOCKUTIL_H
#define NETWORK_SOCKUTIL_H


#include <netdb.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <net/if.h>
#include <netinet/in.h>
#include <netinet/tcp.h>

#include <map>
#include <vector>
#include <string>
#include <string.h>
#include <stdint.h>

using namespace std;

namespace toolkit {

//套接字工具类，封装了socket、网络的一些基本操作
class SockUtil {
public:
	static int connect(const char *host, uint16_t port, bool bAsync = true,const char *localIp = "0.0.0.0",uint16_t localPort = 0);
	static int listen(const uint16_t port, const char *localIp = "0.0.0.0", int backLog = 1024);
	static int bindUdpSock(const uint16_t port, const char *localIp = "0.0.0.0");
	static int bindSock(int sockFd,const char *localIp,uint16_t port);

	static int setNoDelay(int sockFd, bool on = true);
	static int setNoSigpipe(int sock);
	static int setNoBlocked(int sock, bool noblock = true);
	static int setRecvBuf(int sock, int size = 256 * 1024);
	static int setSendBuf(int sock, int size = 256 * 1024);
	static int setReuseable(int sockFd, bool on = true);
	static int setBroadcast(int sockFd, bool on = true);
	static int setKeepAlive(int sockFd, bool on = true);
	static bool getDomainIP(const char *host,uint16_t port,struct sockaddr &addr);
	//组播相关
	static int setMultiTTL(int sockFd, uint8_t ttl = 64);
	static int setMultiIF(int sockFd, const char *strLocalIp);
	static int setMultiLOOP(int sockFd, bool bAccept = false);
	static int joinMultiAddr(int sockFd, const char *strAddr, const char* strLocalIp = "0.0.0.0");
	static int leaveMultiAddr(int sockFd, const char *strAddr, const char* strLocalIp = "0.0.0.0");
	static int joinMultiAddrFilter(int sockFd, const char* strAddr, const char* strSrcIp, const char* strLocalIp = "0.0.0.0");
	static int leaveMultiAddrFilter(int sockFd, const char* strAddr, const char* strSrcIp, const char* strLocalIp = "0.0.0.0");

	static int getSockError(int sockFd);
	static int setCloseWait(int sockFd, int second = 0);
	static vector<map<string,string> > getInterfaceList();

	static string get_local_ip(int fd);
	static string get_local_ip();
	static uint16_t get_local_port(int fd);
	static string get_peer_ip(int fd);
	static uint16_t get_peer_port(int fd);

	//获取网卡ip
	static string get_ifr_ip(const char *ifrName);
    //获取网卡名
	static string get_ifr_name(const char *localIp);
    //根据网卡名获取子网掩码
	static string get_ifr_mask(const char *ifrName);
    //根据网卡名获取广播地址
	static string get_ifr_brdaddr(const char *ifrName);
    //是否为同一网段
	static bool in_same_lan(const char *myIp, const char *dsrIp);

};

}  // namespace toolkit

#endif // !NETWORK_SOCKUTIL_H
