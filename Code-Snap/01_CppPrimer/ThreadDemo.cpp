//
// Created by root on 19-6-21.
//

#include "ThreadDemo.h"
#include <thread>
#include <vector>
#include <iostream>
#include <chrono>

using namespace std;
ThreadDemo::ThreadDemo()
:m_i(10)
{}

ThreadDemo::~ThreadDemo() {

}

ThreadDemo *ThreadDemo::Inst() {
    static ThreadDemo sInst;
    return &sInst;
}

void ThreadDemo::testCase() {
    vector<thread> threads;

    for(int i = 0; i < 10; i++)
    {
        threads.emplace_back([this](int i){
            while(this->m_i > 0)
            {
                this->m_i--;
                cout << "ID:"<<this_thread::get_id() << "\t value:" << i << endl;
                this_thread::sleep_for(chrono::milliseconds(10-i));
            }
            },i);
    }

    
    for(auto &i : threads)
        i.join();

    cout << m_i << endl;
}

void ThreadDemo::testCase2() {

}
