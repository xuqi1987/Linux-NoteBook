//
// Created by xuqi on 2019-07-22.
//

#ifndef V2XBROKER_H
#define V2XBROKER_H
#include "V2xThread.h"
#include "Thread/ThreadPool.h"
#include "Util/RecycleResourcePool.h"
#include "V2xMsg.h"
#include "V2xScene.h"
#include "MsgQueue.h"


using namespace std;
using namespace v2x;
using namespace toolkit;
using namespace mwkit;

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
    void setSceneOutQueue(V2xScene::Queue::Ptr &sceneOutQueue);

private:
    ThreadPool::Ptr _scene_thread_pool;
    V2xMsg::Queue::Ptr _hv_data_queue;
    V2xMsg::Queue::Ptr _rv_data_queue;
    V2xScene::Pool _scene_pool;
    V2xScene::Queue::Ptr _scene_out_queue;
};

}

#endif //V2XBROKER_H
