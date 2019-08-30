

//
// Created by root on 19-8-30.
//

#ifndef CV2X_HTTPREQUESTER_H
#define CV2X_HTTPREQUESTER_H

#include "HttpClientImp.h"
namespace toolkit {

class HttpRequester : public HttpClientImp
{
public:
    typedef std::shared_ptr<HttpRequester> Ptr;
    typedef std::function<void(const SockException &ex,const string &status,const HttpHeader &header,const string &strRecvBody)> HttpRequesterResult;
    HttpRequester();
    virtual ~HttpRequester();
    void startRequester(const string &url,const HttpRequesterResult &onResult,float timeOutSecond = 10);
    void clear() override ;
private:
    int64_t onResponseHeader(const string &status,const HttpHeader &headers) override;
    void onResponseBody(const char *buf,int64_t size,int64_t recvedSize,int64_t totalSize)  override;
    void onResponseCompleted() override;
    void onDisconnect(const SockException &ex) override;
private:
    string _strRecvBody;
    HttpRequesterResult _onResult;
};
}




#endif //CV2X_HTTPREQUESTER_H
