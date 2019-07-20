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
#include "v2xFacility/V2xMsg.h"
#include "Thread/ThreadPool.h"
#include "v2xFacility/V2xITSProducer.h"
#include "v2xFacility/V2xGNSSProducer.h"
#include "v2xFacility/V2xCANProducer.h"
#include "v2xFacility/V2xFacilityAPI.h"
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

 private:
    V2xFacilityAPI::Queue::Ptr _hv_data_queue;
    V2xFacilityAPI::Queue::Ptr _rv_data_queue;
};
}


#endif //CV2X_V2XAPP_H
