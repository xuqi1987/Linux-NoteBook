//
// Created by xuqi on 2019-07-22.
//

#ifndef V2XRECEIVER_H
#define V2XRECEIVER_H
#include "v2xUtil/V2xThread.h"
#include <memory>
#include <thread>
#include <future>
#include "Util/Logger.h"
#include "Util/RecycleResourcePool.h"
#include "v2xUtil/V2xMsgQueue.h"
#include "V2xMsg.h"
#include "Thread/ThreadPool.h"
#include "v2xStack/V2xITSProducer.h"
#include "v2xStack/V2xGNSSProducer.h"
#include "v2xStack/V2xCANProducer.h"
#include "v2xStack/v2xStackAPI.h"
#include "V2xRvFilter.h"

using namespace std;
using namespace v2x;
using namespace toolkit;

namespace v2x {


class V2xReceiver : public V2xThread
{
public:
    typedef shared_ptr<V2xReceiver> Ptr;

    V2xReceiver();
    void run() override;
    void distribute();

    void setHvDataQueue(V2xMsg::Queue::Ptr &q);
    void setRvDataQueue(V2xMsg::Queue::Ptr &q);

private:
    V2xMsg::Queue::Ptr _hv_data_queue;
    V2xMsg::Queue::Ptr _rv_data_queue;
    V2xMsg::ValuePtr _curCar;

    V2xRvFilter::Ptr _filter;
};
}


#endif //V2XRECEIVER_H
