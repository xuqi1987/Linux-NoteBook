//
// Created by xuqi on 2019-07-22.
//

#ifndef V2XBROKER_H
#define V2XBROKER_H
#include "v2xUtil/V2xThread.h"
#include "Thread/ThreadPool.h"
#include "Util/RecycleResourcePool.h"
#include "v2xUtil/V2xMsg.h"
#include "v2xUtil/V2xSceneMsg.h"
#include "v2xUtil/V2xMsgQueue.h"


using namespace std;
using namespace v2x;
using namespace toolkit;


namespace v2x {

class V2xBroker : public V2xThread
{
public:

    V2xBroker();
    typedef shared_ptr<V2xBroker> Ptr;

    void sceneCheck();
    void run() override;
    void setHvDataQueue(V2xMsg::Queue::Ptr &hvDataQueue);
    void setRvDataQueue(V2xMsg::Queue::Ptr &rvDataQueue);
    void setSceneOutQueue(V2xSceneMsg::Queue::Ptr &sceneOutQueue);

private:
    ThreadPool::Ptr _scene_thread_pool;
    V2xMsg::Queue::Ptr _hv_data_queue;
    V2xMsg::Queue::Ptr _rv_data_queue;
    V2xSceneMsg::Pool _scene_pool;
    V2xSceneMsg::Queue::Ptr _scene_out_queue;
};

}

#endif //V2XBROKER_H
