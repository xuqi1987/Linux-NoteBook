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
#include "V2xMsgQueue.h"
#include "V2xMsg.h"
#include "Thread/ThreadPool.h"
#include "Thread/ThreadPool.h"
#include "V2xRvFilter.h"
#include "V2xReceiverProxy.h"

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
    void setHvDataQueue(V2xMsg::Queue::Ptr &q);
    void setRvDataQueue(V2xMsg::Queue::Ptr &q);

private:
    void distribute(V2xMsg::ValuePtr && msg);

private:
    V2xMsg::Queue::Ptr _hv_data_queue;
    V2xMsg::Queue::Ptr _rv_data_queue;
    V2xMsg::ValuePtr _curCar;

    V2xRvFilter::Ptr _filter;
    // 新建资源池
    RecycleResourcePool<V2xMsg> _recycleResourcePool;

    V2xReceiverProxy::Ptr _recv_proxy;



};
}


#endif //V2XRECEIVER_H
