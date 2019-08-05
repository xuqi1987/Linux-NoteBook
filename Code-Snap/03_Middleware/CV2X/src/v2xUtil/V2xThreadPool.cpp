//
// Created by xuqi on 2019-07-31.
//

#include "V2xThreadPool.h"

namespace v2x {

V2xThreadPool::V2xThreadPool(int threadnum)
:_thread_num(threadnum)
{
    _thread = make_shared<ThreadPool>(_thread_num, ThreadPool::PRIORITY_HIGHEST, false);
}

V2xThreadPool::~V2xThreadPool()
{

}

void V2xThreadPool::start()
{
    for (int i =0 ; i < _thread_num; i++)
    {
        _thread->async(bind(&V2xThreadPool::run, this,i));
        _thread->start();
    }

}
}
