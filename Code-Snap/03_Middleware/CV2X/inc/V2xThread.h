//
// Created by xuqi on 2019-07-20.
//

#ifndef V2XTHREAD_H
#define V2XTHREAD_H

#include "Thread/ThreadPool.h"

using namespace toolkit;

namespace v2x {

class V2xThread
{
public:
    V2xThread();
    virtual ~V2xThread();
    virtual void Start();
    virtual void Run() = 0;

private:
    ThreadPool::Ptr m_pThread;

};

}




#endif //V2XTHREAD_H
