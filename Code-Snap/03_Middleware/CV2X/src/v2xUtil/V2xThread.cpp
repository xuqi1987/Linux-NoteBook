//
// Created by xuqi on 2019-07-20.
//

#include "V2xThread.h"
#include "Util/Logger.h"
namespace v2x
{

v2x::V2xThread::V2xThread()
{
    m_pThread = make_shared<ThreadPool>(1, ThreadPool::PRIORITY_HIGHEST, false);
}

v2x::V2xThread::~V2xThread()
{

}

void v2x::V2xThread::Start()
{
    m_pThread->async(bind(&V2xThread::Run, this));

    m_pThread->start();
}

}
