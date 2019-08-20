
#include "TcpClient.h"

namespace toolkit {

TcpClient::TcpClient(const EventPoller::Ptr &poller) : SocketHelper(nullptr) {
    _poller = poller;
    if(!_poller){
        _poller = EventPollerPool::Instance().getPoller();
    }
}

TcpClient::~TcpClient() {}

void TcpClient::shutdown(const SockException &ex) {
    _managerTimer.reset();
    SocketHelper::shutdown(ex);
}

bool TcpClient::alive() {
    bool ret = _sock.operator bool() && _sock->rawFD() >= 0;
    return ret;
}

void TcpClient::setNetAdapter(const string &localIp){
    _netAdapter = localIp;
}

void TcpClient::startConnect(const string &strUrl, uint16_t iPort,float fTimeOutSec) {
    weak_ptr<TcpClient> weakSelf = shared_from_this();

    _managerTimer.reset();
    _sock = std::make_shared<Socket>(_poller);
    _sock->connect(strUrl, iPort, [weakSelf](const SockException &err){
        auto strongSelf = weakSelf.lock();
        if(strongSelf){
            strongSelf->onSockConnect(err);
        }
    }, fTimeOutSec,_netAdapter.data());
}
void TcpClient::onSockConnect(const SockException &ex) {
    if(ex){
        //连接失败
        _managerTimer.reset();
        onConnect(ex);
        return;
    }

    weak_ptr<TcpClient> weakSelf = shared_from_this();
    _sock->setOnErr([weakSelf](const SockException &ex) {
        auto strongSelf = weakSelf.lock();
        if (!strongSelf) {
            return;
        }
        strongSelf->_managerTimer.reset();
        strongSelf->onErr(ex);
    });
    _sock->setOnFlush([weakSelf]() {
        auto strongSelf = weakSelf.lock();
        if (!strongSelf) {
            return false;
        }
        strongSelf->onFlush();
        return true;
    });
    _sock->setOnRead([weakSelf](const Buffer::Ptr &pBuf, struct sockaddr * , int) {
        auto strongSelf = weakSelf.lock();
        if (!strongSelf) {
            return;
        }
        strongSelf->onRecv(pBuf);
    });
    _managerTimer = std::make_shared<Timer>(2,[weakSelf](){
        auto strongSelf = weakSelf.lock();
        if (!strongSelf) {
            return false;
        }
        strongSelf->onManager();
        return true;
    },_poller);

    onConnect(ex);
}

} /* namespace toolkit */
