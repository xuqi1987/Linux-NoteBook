//
// Created by xuqi on 2019-07-13.
//

#ifndef CV2X_SRC_V2X_V2XGNSSPRODUCER_H_
#define CV2X_SRC_V2X_V2XGNSSPRODUCER_H_

#include <iostream>
#include <memory>
#include <thread>
#include <future>
#include "Util/Logger.h"
#include "Util/RecycleResourcePool.h"
#include "MsgQueue.h"
#include "V2xMsg.h"
#include "Producer.h"

using namespace std;
using namespace v2x;
using namespace toolkit;
using namespace mwkit;

class V2xGNSSProducer : public Producer {

 public:

  typedef shared_ptr<V2xGNSSProducer> Ptr;
  typedef RecycleResourcePool<V2xMsg>::ValuePtr ValuePtr;
  typedef MsgQueue<ValuePtr> Queue;

  V2xGNSSProducer(Queue::Ptr &queue);

  virtual ~V2xGNSSProducer();
  void run() override;

 private:
  RecycleResourcePool<V2xMsg> _hv_gnss_pool;
  Queue::Ptr _hv_gnss_queue;

};

#endif //CV2X_SRC_V2X_V2XGNSSPRODUCER_H_
