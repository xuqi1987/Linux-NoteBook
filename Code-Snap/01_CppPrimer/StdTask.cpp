//
// Created by xuqi on 2019-06-13.
//

#include "StdTask.h"
void StdTask::create(function<void()> f)
{
    m_pThread = new thread(f);
}
void StdTask::start()
{
    if (nullptr != m_pThread)
    {
        m_pThread->join();
    }
}
StdTask::StdTask(const string &name)
    : Task(name)
{

}
StdTask::~StdTask()
{
    delete m_pThread;
    m_pThread = nullptr;
}
