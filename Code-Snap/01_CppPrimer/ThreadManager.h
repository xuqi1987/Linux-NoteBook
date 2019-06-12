//
// Created by xuqi on 2019-06-12.
//

#ifndef THREADMANAGER_H
#define THREADMANAGER_H

#include <iostream>
#include <thread>

using namespace std;



class ThreadManager
{
public:
    static ThreadManager* Inst();
    void runCase1();
    void runCase2();

private:
    ThreadManager();

};


#endif //THREADMANAGER_H
