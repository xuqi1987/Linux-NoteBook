//
// Created by xuqi on 2019-07-22.
//

#ifndef V2XBROKER_H
#define V2XBROKER_H
#include "V2xThread.h"
#include "Thread/ThreadPool.h"
#include "Util/RecycleResourcePool.h"
#include "V2xMsg.h"
#include "V2xSceneMsg.h"
#include "V2xMsgQueue.h"
#include "V2xRvThreadPool.h"

using namespace std;
using namespace v2x;
using namespace toolkit;


namespace v2x {

class V2xHvMapSpatCal;

class V2xBroker : public V2xThread , public enable_shared_from_this<V2xBroker>
{
public:

    V2xBroker();
    typedef shared_ptr<V2xBroker> Ptr;

    void sceneCheck();
    void run() override;
    void setHvDataQueue(V2xMsg::Queue::Ptr &hvDataQueue);
    void setRvDataQueue(V2xMsg::Queue::Ptr &rvDataQueue);
    void setSceneOutQueue(V2xSceneMsg::Queue::Ptr &sceneOutQueue);

    friend class V2xHvMapSpatCal;
private:
    ThreadPool::Ptr _rvThreadPool;
    V2xMsg::Queue::Ptr _hv_data_queue;
    V2xMsg::Queue::Ptr _rv_data_queue;
    V2xSceneMsg::Pool _scene_pool;
    V2xSceneMsg::Queue::Ptr _scene_out_queue;
    shared_ptr<V2xHvMapSpatCal> _hv_map_spat;

};

}

#endif //V2XBROKER_H
