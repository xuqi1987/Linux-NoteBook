//
// Created by root on 19-7-12.
//

#include "Broker.h"

Broker::Broker()
: Broker(1) {

}

Broker::Broker(int threadnum)
:_thread_num(threadnum)
{
  _thread = make_shared<ThreadPool>(threadnum,ThreadPool::PRIORITY_NORMAL,false);
}

Broker::~Broker() {

}
void Broker::start() {
  for (int i = 0; i < _thread_num; i++) {
    _thread->async(bind(&Broker::run,this,i));
  }

  _thread->start();
}
