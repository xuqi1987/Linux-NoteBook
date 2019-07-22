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
#include "v2xApp/V2xMsg.h"
#include "v2xApp/V2xThread.h"

#include "V2xCANProducer.h"

using namespace std;
using namespace v2x;
using namespace toolkit;
using namespace mwkit;

namespace v2x
{
class V2xGNSSProducer: public V2xThread
{
public:
    typedef shared_ptr<V2xGNSSProducer> Ptr;
    typedef RecycleResourcePool<V2xMsg>::ValuePtr ValuePtr;
    typedef MsgQueue<ValuePtr> Queue;

    V2xGNSSProducer(Queue::Ptr &queue);

    virtual ~V2xGNSSProducer();
    void run() override;

private:

    V2xCANProducer::Ptr _can_producer;

    RecycleResourcePool<V2xMsg> _hv_bsm_pool;
    Queue::Ptr _hv_bsm_queue;

    ThreadPool::Ptr _thread;

};
}

#endif //CV2X_SRC_V2X_V2XGNSSPRODUCER_H_
