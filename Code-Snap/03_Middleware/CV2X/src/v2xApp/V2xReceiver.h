//
// Created by xuqi on 2019-07-22.
//

#ifndef V2XRECEIVER_H
#define V2XRECEIVER_H
#include "V2xThread.h"
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
#include "V2xRvFilter.h"

using namespace std;
using namespace v2x;
using namespace toolkit;

namespace v2x {


class V2xReceiver : public V2xThread
{
public:
    typedef shared_ptr<V2xReceiver> Ptr;
    typedef RecycleResourcePool<V2xMsg>::ValuePtr ValuePtr;
    typedef MsgQueue<ValuePtr> Queue;

    V2xReceiver();
    void run() override;
    void distribute();

    void setHvDataQueue(Queue::Ptr &q);
    void setRvDataQueue(Queue::Ptr &q);

private:
    Queue::Ptr _hv_data_queue;
    Queue::Ptr _rv_data_queue;
    ValuePtr _curCar;

    V2xRvFilter::Ptr _filter;
};
}


#endif //V2XRECEIVER_H
