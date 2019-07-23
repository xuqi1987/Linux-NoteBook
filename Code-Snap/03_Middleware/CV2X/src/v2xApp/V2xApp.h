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
#include "v2xStack/V2xITSProducer.h"
#include "v2xStack/V2xGNSSProducer.h"
#include "v2xStack/V2xCANProducer.h"
#include "v2xStack/v2xStackAPI.h"

#include "V2xRvAsyncFilter.h"
#include "V2xReceiver.h"
#include "V2xBroker.h"
#include "V2xSender.h"

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

 private:
    V2xReceiver::Ptr _receiver;
    V2xReceiver::Queue::Ptr _hv_out_pool;
    V2xReceiver::Queue::Ptr _rv_out_pool;


    V2xBroker::Ptr _broker;
    V2xSender::Ptr _sender;
};
}


#endif //CV2X_V2XAPP_H
