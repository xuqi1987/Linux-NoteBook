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
    void runRVFilterThread();
    void runCANRecvThread();

    RecycleResourcePool<V2xcar> cars_pool;
    MsgQueue<decltype(cars_pool)::ValuePtr> recv_queue;

};
}


#endif //CV2X_V2XAPP_H
