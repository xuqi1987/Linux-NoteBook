//
// Created by root on 19-8-30.
//

#include "HttpClientImp.h"
namespace toolkit {

void HttpClientImp::onConnect(const SockException &ex) {
    if(!_isHttps){
        HttpClient::onConnect(ex);
    } else {
        TcpClientWithSSL<HttpClient>::onConnect(ex);
    }

}
}