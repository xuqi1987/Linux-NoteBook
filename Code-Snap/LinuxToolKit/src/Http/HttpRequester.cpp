//
// Created by root on 19-8-30.
//

#include "HttpRequester.h"

namespace toolkit {
HttpRequester::HttpRequester(){

}
HttpRequester::~HttpRequester(){

}

int64_t HttpRequester::onResponseHeader(const string &status,const HttpHeader &headers) {
    _strRecvBody.clear();
    //无Content-Length字段时默认后面没有content
    return 0;
}

void HttpRequester::onResponseBody(const char *buf,int64_t size,int64_t recvedSize,int64_t totalSize) {
    _strRecvBody.append(buf,size);
}

void HttpRequester::onResponseCompleted() {
    if(_onResult){
        _onResult(SockException(),responseStatus(),responseHeader(),_strRecvBody);
        _onResult = nullptr;
    }
}

void HttpRequester::onDisconnect(const SockException &ex){
    if(_onResult){
        _onResult(ex,responseStatus(),responseHeader(),_strRecvBody);
        _onResult = nullptr;
    }
}

void HttpRequester::startRequester(const string &url,const HttpRequesterResult &onResult , float timeOutSecond){
    _onResult = onResult;
    sendRequest(url,timeOutSecond);
}

void HttpRequester::clear() {
    HttpClientImp::clear();
    _strRecvBody.clear();
    _onResult = nullptr;
}

}