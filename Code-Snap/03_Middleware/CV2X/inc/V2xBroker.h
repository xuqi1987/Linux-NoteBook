//
// Created by xuqi on 2019-07-22.
//

#ifndef V2XBROKER_H
#define V2XBROKER_H
#include "V2xThread.h"
#include "Thread/ThreadPool.h"
#include "Util/ResourcePool.h"
#include "V2xMsg.h"
#include "V2xSceneMsg.h"
#include "V2xMsgQueue.h"

using namespace std;
using namespace v2x;
using namespace toolkit;


namespace v2x {

class V2xHvMapSpatCal;
class V2xRvThreadPool;

class V2xBroker : public V2xThread , public enable_shared_from_this<V2xBroker>
{
public:

    V2xBroker();
    typedef shared_ptr<V2xBroker> Ptr;

    void Run() override;
    void setHvDataQueue(V2xMsg::Queue::Ptr &pHvDataQueue);
    void setRvDataQueue(V2xMsg::Queue::Ptr &pRvDataQueue);
    void setSceneOutQueue(V2xSceneMsg::Queue::Ptr &pSceneOutQueue);

    friend class V2xHvMapSpatCal;
    friend class V2xRvThreadPool;
private:

    V2xMsg::Queue::Ptr m_pHvDataQueue; // RVMsgQueue
    V2xMsg::Queue::Ptr m_pRvDataQueue; // HVMsgQueue (Map/Spat/HV)
    V2xMsg::Queue::Ptr m_pBsmQueue; // BSMMsgQueue
    V2xSceneMsg::Pool m_scenePool;
    V2xSceneMsg::Queue::Ptr m_pSceneOutQueue;
    shared_ptr<V2xHvMapSpatCal> m_pHvMapSpat;
    shared_ptr<V2xRvThreadPool> m_pRvThreads;
    V2xMsg::ValuePtr m_pHvCurMsg;
    V2xMsg::ValuePtr m_pMapCurMsg;
    V2xMsg::ValuePtr m_pSpatCurMsg;
    V2xMsg::ValuePtr m_pRsiCurMsg;
    V2xMsg::ValuePtr m_pRsmCurMsg;
};

}

#endif //V2XBROKER_H
