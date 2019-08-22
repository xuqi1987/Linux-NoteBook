//
// Created by xuqi on 2019-07-31.
//

#ifndef V2XTHREADPOOL_H
#define V2XTHREADPOOL_H

#include "Thread/ThreadPool.h"

using  namespace toolkit;

namespace v2x {

class V2xThreadPool
{
public:
    V2xThreadPool(int iThreadnum = 1);
    virtual ~V2xThreadPool();
    void Start();
    virtual void Run(int iIndex) = 0;
private:
    ThreadPool::Ptr m_pThreads;
    int m_iThreadNum;
};

}



#endif //V2XTHREADPOOL_H
