
#ifndef SERVER_SESSION_H_
#define SERVER_SESSION_H_
#include <memory>
#include <sstream>
#include "Socket.h"
#include "Util/Logger.h"
#include "Util/Mini.h"
#include "Util/SSLBox.h"
#include "Thread/ThreadPool.h"

using namespace std;

namespace toolkit {

class TcpServer;
class TcpSession:
		public std::enable_shared_from_this<TcpSession> ,
		public SocketHelper{
public:
    typedef std::shared_ptr<TcpSession> Ptr;

	TcpSession(const Socket::Ptr &pSock);
	virtual ~TcpSession();
    //接收数据入口
	virtual void onRecv(const Buffer::Ptr &) = 0;
    //收到eof或其他导致脱离TcpServer事件的回调
	virtual void onError(const SockException &err) = 0;
    //每隔一段时间触发，用来做超时管理
	virtual void onManager() =0;
    //在创建TcpSession后，TcpServer会把自身的配置参数通过该函数传递给TcpSession
    virtual void attachServer(const TcpServer &server){};
    //作为该TcpSession的唯一标识符
    virtual string getIdentifier() const;
    //安全的脱离TcpServer并触发onError事件
    void safeShutdown(const SockException &ex = SockException(Err_shutdown, "self shutdown"));
};

template<typename TcpSessionType>
class TcpSessionWithSSL: public TcpSessionType {
public:
	template<typename ...ArgsType>
	TcpSessionWithSSL(ArgsType &&...args):TcpSessionType(std::forward<ArgsType>(args)...){
		_sslBox.setOnEncData([&](const Buffer::Ptr &buffer){
			public_send(buffer);
		});
		_sslBox.setOnDecData([&](const Buffer::Ptr &buffer){
            public_onRecv(buffer);
		});
	}
	virtual ~TcpSessionWithSSL(){}

	void onRecv(const Buffer::Ptr &pBuf) override{
		_sslBox.onRecv(pBuf);
	}

	//添加public_onRecv和public_send函数是解决较低版本gcc一个lambad中不能访问protected或private方法的bug
	inline void public_onRecv(const Buffer::Ptr &pBuf){
        TcpSessionType::onRecv(pBuf);
    }
    inline void public_send(const Buffer::Ptr &pBuf){
        TcpSessionType::send(pBuf);
    }
protected:
	virtual int send(const Buffer::Ptr &buf) override{
		_sslBox.onSend(buf);
		return buf->size();
	}
private:
	SSL_Box _sslBox;
};

#define TraceP(ptr) TraceL << ptr << "(" << ptr->get_peer_ip() << ":" << ptr->get_peer_port() << ") "
#define DebugP(ptr) DebugL << ptr << "(" << ptr->get_peer_ip() << ":" << ptr->get_peer_port() << ") "
#define InfoP(ptr) InfoL << ptr << "(" << ptr->get_peer_ip() << ":" << ptr->get_peer_port() << ") "
#define WarnP(ptr) WarnL << ptr << "(" << ptr->get_peer_ip() << ":" << ptr->get_peer_port() << ") "
#define ErrorP(ptr) ErrorL << ptr << "(" << ptr->get_peer_ip() << ":" << ptr->get_peer_port() << ") "


} /* namespace toolkit */

#endif /* SERVER_SESSION_H_ */
