//
// Created by root on 19-7-12.
//

#ifndef CV2X_V2XITSPRODUCER_H
#define CV2X_V2XITSPRODUCER_H
#include <iostream>
#include <memory>
#include <thread>
#include <future>
#include "Util/Logger.h"
#include "Util/RecycleResourcePool.h"
#include "MsgQueue.h"
#include "v2xApp/V2xMsg.h"
#include "v2xApp/V2xRvAsyncFilter.h"
#include "v2xApp/V2xThread.h"

using namespace std;
using namespace v2x;
using namespace toolkit;
using namespace mwkit;

namespace v2x
{
class V2xITSProducer: public V2xThread
{
public:

    typedef shared_ptr<V2xITSProducer> Ptr;
    typedef RecycleResourcePool<V2xMsg>::ValuePtr ValuePtr;
    typedef MsgQueue<ValuePtr> Queue;

    V2xITSProducer(Queue::Ptr &queue);
    virtual ~V2xITSProducer();
    void run() override;

private:
    RecycleResourcePool<V2xMsg> _rv_bsm_pool;
    Queue::Ptr _rv_bsm_queue;
    //Queue::Ptr _tmp_rv_bsm_queue;

    //V2xRvAsyncFilter::Ptr _filter;
};
}

#endif //CV2X_V2XITSPRODUCER_H
