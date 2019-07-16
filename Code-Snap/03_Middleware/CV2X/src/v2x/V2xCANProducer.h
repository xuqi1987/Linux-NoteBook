//
// Created by xuqi on 2019-07-16.
//

#ifndef V2XCANPRODUCER_H
#define V2XCANPRODUCER_H

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


class V2xCANProducer: public Producer
{
public:

    typedef shared_ptr<V2xCANProducer> Ptr;
    typedef RecycleResourcePool<V2xMsg>::ValuePtr ValuePtr;
    typedef MsgQueue<ValuePtr> Queue;

    V2xCANProducer(Queue::Ptr &queue);
    virtual ~V2xCANProducer();
    void run() override;

private:
    RecycleResourcePool<V2xMsg> _hv_can_pool;
    Queue::Ptr _hv_can_queue;
};


#endif //V2XCANPRODUCER_H
