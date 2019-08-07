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
    V2xThreadPool(int threadnum = 1);
    virtual ~V2xThreadPool();
    void start();
    virtual void run(int num) = 0;
private:
    ThreadPool::Ptr _thread;
    int _thread_num;
};

}



#endif //V2XTHREADPOOL_H
