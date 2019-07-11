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
#include "v2x/MsgQueue.h"
#include "v2x/V2xcar.h"
#include "Thread/ThreadPool.h"


using namespace std;
using namespace v2x;
using namespace toolkit;

namespace v2x
{
class V2xApp: public std::enable_shared_from_this<V2xApp>
{
public:
    void run();

private:

    void runGNSSThread();
    void runRVFilterThread(int i);
    void runCANRecvThread();

 private:

    ThreadPool::Ptr _thread_pool;
    RecycleResourcePool<V2xcar> _cars_pool;
    MsgQueue<decltype(_cars_pool)::ValuePtr> _recv_queue;
    

};
}


#endif //CV2X_V2XAPP_H
