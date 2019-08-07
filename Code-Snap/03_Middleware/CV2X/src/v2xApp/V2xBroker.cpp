//
// Created by xuqi on 2019-07-22.
//

#include "V2xBroker.h"
#include "V2xHvMapSpatCal.h"
#include "V2xRvThreadPool.h"
namespace v2x {

void V2xBroker::run()
{
    _rv_threads  = make_shared<V2xRvThreadPool>(this->shared_from_this(),10);
    _hv_map_spat = make_shared<V2xHvMapSpatCal>(this->shared_from_this());

    _rv_threads->start();
    _hv_map_spat->run();
}

V2xBroker::V2xBroker()
{
    _scene_pool.setSize(100);
}

void V2xBroker::setHvDataQueue(V2xMsg::Queue::Ptr &hvDataQueue)
{
    _hv_data_queue = hvDataQueue;
}

void V2xBroker::setRvDataQueue(V2xMsg::Queue::Ptr &rvDataQueue)
{
    _rv_data_queue = rvDataQueue;
}

void V2xBroker::setSceneOutQueue(V2xSceneMsg::Queue::Ptr &sceneOutQueue)
{
    _scene_out_queue = sceneOutQueue;
}


}

