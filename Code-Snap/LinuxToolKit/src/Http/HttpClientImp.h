
//
// Created by root on 19-8-30.
//

#ifndef CV2X_HTTPCLIENTIMP_H
#define CV2X_HTTPCLIENTIMP_H
#include "HttpClient.h"
#include "Util/SSLBox.h"

namespace toolkit {

class HttpClientImp: public TcpClientWithSSL<HttpClient> {
public:
    typedef std::shared_ptr<HttpClientImp> Ptr;
    HttpClientImp() {}
    virtual ~HttpClientImp() {}
protected:
    void onConnect(const SockException &ex)  override ;
};
}

#endif //CV2X_HTTPCLIENTIMP_H
