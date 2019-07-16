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
#include "v2x/message/V2xMsg.h"
#include "Producer.h"

using namespace std;
using namespace v2x;
using namespace toolkit;
using namespace mwkit;

class V2xITSProducer : public Producer
{
public:

    typedef shared_ptr<V2xITSProducer> Ptr;
    typedef RecycleResourcePool<V2xMsg>::ValuePtr ValuePtr;
    typedef MsgQueue<ValuePtr> Queue;


    V2xITSProducer(Queue::Ptr &queue);
    virtual ~V2xITSProducer();
    void recv() override;

 private:
    RecycleResourcePool<V2xMsg> _othercars;
    Queue::Ptr _data_queue;
};


#endif //CV2X_V2XITSPRODUCER_H
