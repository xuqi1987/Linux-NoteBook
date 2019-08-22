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
#include "Util/ResourcePool.h"
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
    virtual ~V2xReceiver();

    void Run() override;
    void SetHvDataQueue(V2xMsg::Queue::Ptr &pQueue);
    void SetRvDataQueue(V2xMsg::Queue::Ptr &pQueue);

private:
    void distribute(V2xMsg::ValuePtr && pMsg);

private:
    V2xMsg::Queue::Ptr m_pHvDataQueue;
    V2xMsg::Queue::Ptr m_pRvDataQueue;
    V2xMsg::ValuePtr m_pCurCar;

    V2xRvFilter::Ptr m_pFilter;
    // 新建资源池
    ResourcePool<V2xMsg> m_recycleResourcePool;

    V2xReceiverProxy::Ptr m_pRecvProxy;



};
}


#endif //V2XRECEIVER_H
