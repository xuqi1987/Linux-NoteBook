

#include <string>
#include "TcpSession.h"


namespace toolkit {

TcpSession::TcpSession( const Socket::Ptr &sock) : SocketHelper(sock) {
}

TcpSession::~TcpSession() {
}

string TcpSession::getIdentifier() const{
    return to_string(reinterpret_cast<uint64_t>(this));
}

void TcpSession::safeShutdown(const SockException &ex){
    std::weak_ptr<TcpSession> weakSelf = shared_from_this();
    async_first([weakSelf,ex](){
        auto strongSelf = weakSelf.lock();
        if(strongSelf){
            strongSelf->shutdown(ex);
        }
    });
}

} /* namespace toolkit */

