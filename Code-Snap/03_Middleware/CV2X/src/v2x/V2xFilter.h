//
// Created by xuqi on 2019-07-13.
//

#ifndef CV2X_SRC_V2X_V2XFILTER_H_
#define CV2X_SRC_V2X_V2XFILTER_H_
#include <iostream>
#include <memory>
#include <thread>
#include <future>
#include "Util/Logger.h"
#include "Util/RecycleResourcePool.h"
#include "MsgQueue.h"
#include "v2x/message/V2xMsgBSM.h"
#include "Broker.h"

using namespace std;
using namespace v2x;
using namespace toolkit;
using namespace mwkit;


class V2xFilter : public Broker{
 public:

  typedef shared_ptr<V2xFilter> Ptr;
  typedef RecycleResourcePool<V2xMsgBSM>::ValuePtr ValuePtr;
  typedef MsgQueue<ValuePtr> Queue;

  V2xFilter(int threadnum,Queue::Ptr &iQueue,Queue::Ptr &oQueue);
  void work(int num) override;

 private:
  Queue::Ptr _input_queue;
  Queue::Ptr _output_queue;
};

#endif //CV2X_SRC_V2X_V2XFILTER_H_
