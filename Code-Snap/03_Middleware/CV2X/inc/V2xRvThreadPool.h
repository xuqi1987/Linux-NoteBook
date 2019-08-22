//
// Created by xuqi on 2019-08-07.
//

#ifndef V2XRVTHREADPOOL_H
#define V2XRVTHREADPOOL_H
#include "V2xThreadPool.h"
#include "V2xBroker.h"

namespace v2x {

class V2xRvThreadPool : public V2xThreadPool
{
public:
    typedef shared_ptr<V2xRvThreadPool> Ptr;
    V2xRvThreadPool(const shared_ptr<V2xBroker> &pBroker,int iThreadnum);
    void Run(int iIndex) override;

private:
    V2xBroker::Ptr m_pBroker;
};

}


#endif //V2XRVTHREADPOOL_H
