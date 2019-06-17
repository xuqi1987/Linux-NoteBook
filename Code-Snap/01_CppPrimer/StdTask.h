//
// Created by xuqi on 2019-06-13.
//

#ifndef STDTASK_H
#define STDTASK_H
#include "Task.h"
#include <thread>

class StdTask : public Task
{
public:
    StdTask(const string &name);
    virtual ~StdTask();
    virtual void create(function<void()> f) override;
    virtual void start() override;
private:
    thread* m_pThread;

};


#endif //STDTASK_H
