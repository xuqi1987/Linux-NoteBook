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
#include "v2x/MsgQueue.h"
#include "v2x/V2xcar.h"
#include "Thread/ThreadPool.h"

using namespace std;
using namespace v2x;
using namespace toolkit;

class V2xITSProducer
{
public:
    V2xITSProducer(int objnum);
    V2xITSProducer();
    bool get(V2xcar::Ptr car);
    void startWorking();
    virtual ~V2xITSProducer();

private:
    RecycleResourcePool<V2xcar> _othercars;
    MsgQueue<decltype(_othercars)::ValuePtr> _data_queue;

    //MsgQueue<RecycleResourcePool<V2xcar>::ValuePtr> _data_queue;
};


#endif //CV2X_V2XITSPRODUCER_H
