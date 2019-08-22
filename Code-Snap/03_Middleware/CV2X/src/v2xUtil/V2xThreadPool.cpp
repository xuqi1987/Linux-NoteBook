//
// Created by xuqi on 2019-07-31.
//

#include "V2xThreadPool.h"

namespace v2x {

V2xThreadPool::V2xThreadPool(int iThreadnum)
:m_iThreadNum(iThreadnum)
{
    m_pThreads = make_shared<ThreadPool>(m_iThreadNum, ThreadPool::PRIORITY_HIGHEST, false);
}

V2xThreadPool::~V2xThreadPool()
{

}

void V2xThreadPool::Start()
{
    for (int i =0 ; i < m_iThreadNum; i++)
    {
        m_pThreads->async(bind(&V2xThreadPool::Run, this,i));
        m_pThreads->start();
    }

}
}
