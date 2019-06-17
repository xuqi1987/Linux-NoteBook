//
// Created by xuqi on 2019-06-13.
//

#ifndef TASK_H
#define TASK_H
#include <string>
#include <functional>

using namespace std;

class Task
{
public:
    Task(string name) { m_name = name;};
    virtual ~Task() {};
    virtual void create(function<void()> f) = 0;
    virtual void start() = 0;

private:
    string m_name;
};


#endif //TASK_H
