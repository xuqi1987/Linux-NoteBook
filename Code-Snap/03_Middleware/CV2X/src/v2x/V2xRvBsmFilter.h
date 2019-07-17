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
#include "V2xMsg.h"
#include "Broker.h"

using namespace std;
using namespace v2x;
using namespace toolkit;
using namespace mwkit;


class V2xRvBsmFilter : public Broker{
 public:

  typedef shared_ptr<V2xRvBsmFilter> Ptr;
  typedef RecycleResourcePool<V2xMsg>::ValuePtr ValuePtr;
  typedef MsgQueue<ValuePtr> Queue;

  V2xRvBsmFilter(int threadnum,Queue::Ptr &iQueue,Queue::Ptr &oQueue);
  void run(int num) override;

 private:
  Queue::Ptr _input_queue;
  Queue::Ptr _output_queue;
};

#endif //CV2X_SRC_V2X_V2XFILTER_H_
