//
// Created by root on 19-7-12.
//

#ifndef CV2X_BROKER_H
#define CV2X_BROKER_H
#include "Thread/ThreadPool.h"

using namespace toolkit;


class Broker
{
 public:
  Broker();
  Broker(int threadnum);
  virtual ~Broker();
  void start();
  virtual void run(int num) = 0;
 private:
  ThreadPool::Ptr _thread;
  int _thread_num;
};


#endif //CV2X_BROKER_H
