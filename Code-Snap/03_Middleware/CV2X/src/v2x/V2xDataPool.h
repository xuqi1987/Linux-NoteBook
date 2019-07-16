//
// Created by xuqi on 2019-07-13.
//

#ifndef CV2X_SRC_V2X_V2XDATAPOOL_H_
#define CV2X_SRC_V2X_V2XDATAPOOL_H_

#include <iostream>
#include <memory>
#include <thread>
#include <future>
#include "Util/Logger.h"
#include "Util/RecycleResourcePool.h"
#include "MsgQueue.h"
#include "v2x/message/V2xMsg.h"
#include "Thread/ThreadPool.h"
#include "V2xITSProducer.h"
#include "V2xFilter.h"

using namespace std;
using namespace v2x;
using namespace toolkit;

namespace v2x {

class V2xDataPool {
 public:
  V2xITSProducer::Queue::Ptr _its_out_pool;
  V2xFilter::Queue::Ptr _filter_out_pool;

};


}


#endif //CV2X_SRC_V2X_V2XDATAPOOL_H_
