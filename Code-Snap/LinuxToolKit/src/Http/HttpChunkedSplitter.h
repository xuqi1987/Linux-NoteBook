
//
// Created by root on 19-8-30.
//

#ifndef CV2X_HTTPCHUNKEDSPLITTER_H
#define CV2X_HTTPCHUNKEDSPLITTER_H
#include <functional>
#include "HttpRequestSplitter.h"

namespace toolkit {
class HttpChunkedSplitter : public HttpRequestSplitter {
public:
    /**
     * len == 0时代表结束
     */
    typedef std::function<void (const char *data,uint64_t len)> onChunkData;

    HttpChunkedSplitter(const onChunkData &cb){
        _onChunkData = cb;
    };
    ~HttpChunkedSplitter() override {} ;
protected:
    int64_t onRecvHeader(const char *data,uint64_t len) override;
    void onRecvContent(const char *data,uint64_t len) override;
    const char *onSearchPacketTail(const char *data,int len) override;
protected:
    virtual void onRecvChunk(const char *data,uint64_t len){
        if(_onChunkData){
            _onChunkData(data,len);
        }
    };
private:
    onChunkData _onChunkData;
};
}


#endif //CV2X_HTTPCHUNKEDSPLITTER_H
