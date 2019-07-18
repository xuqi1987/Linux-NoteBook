//
// Created by root on 19-7-11.
//

#ifndef CV2X_V2XAPP_H
#define CV2X_V2XAPP_H
#include <iostream>
#include <memory>
#include <thread>
#include <future>
#include "Util/Logger.h"
#include "Util/RecycleResourcePool.h"
#include "MsgQueue.h"
#include "V2xMsg.h"
#include "Thread/ThreadPool.h"
#include "V2xITSProducer.h"
#include "V2xGNSSProducer.h"
#include "V2xCANProducer.h"
#include "V2xRvBsmFilter.h"

using namespace std;
using namespace v2x;
using namespace toolkit;

namespace v2x
{
class V2xApp
{
public:
  V2xApp();
  void run();

  void createProducer();
  void createBroker();
  void createConsumer();

 private:
    V2xITSProducer::Queue::Ptr _rv_data_pool;
    V2xITSProducer::Ptr _rv_producer;

    V2xGNSSProducer::Queue::Ptr _hv_data_pool;
    V2xGNSSProducer::Ptr _hv_producer;




};
}


#endif //CV2X_V2XAPP_H
