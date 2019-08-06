//
// Created by xuqi on 2019-07-22.
//

#include "V2xBroker.h"

namespace v2x {

void V2xBroker::run()
{
    _scene_thread_pool->async(bind(&V2xBroker::sceneCheck, this));
    _scene_thread_pool->start();
}

V2xBroker::V2xBroker()
{
    _scene_thread_pool = make_shared<ThreadPool>(2,ThreadPool::PRIORITY_HIGHEST, false);
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

void V2xBroker::sceneCheck()
{
    V2xMsg::ValuePtr msg;
    V2xSceneMsg::ValuePtr scene;

    while (_rv_data_queue->pop(msg))
    {
        DebugL << "模拟场景判断,如果车辆ID小于5，触发场景:" << msg;

        if (msg->u.rvbsm.getTempId() < 5)
        {
            scene = _scene_pool.obtain();

            if(msg->u.rvbsm.getTempId()== 1)
            {
                scene->setLevel(V2xSceneMsg::LEVEL_1);
                scene->assign(StrPrinter <<"高优先级 场景触发，进程:" << getpid()<< " " <<msg );
                scene->setSecMark(msg->u.rvbsm.getSecMark());
                _scene_out_queue->push(scene);
            }
            else if (msg->u.rvbsm.getTempId()== 2)
            {
                scene->setLevel(V2xSceneMsg::LEVEL_2);
                scene->setSecMark(msg->u.rvbsm.getSecMark());
                scene->assign(StrPrinter <<"中优先级 场景触发，进程:" << getpid()<< " " <<msg);
                _scene_out_queue->push(scene);
            }
            else if (msg->u.rvbsm.getTempId()== 3)
            {
                scene->setLevel(V2xSceneMsg::LEVEL_3);
                scene->setSecMark(msg->u.rvbsm.getSecMark());
                scene->assign(StrPrinter <<"低优先级 场景触发，进程:" << getpid()<< " " <<msg);
                _scene_out_queue->push(scene);
            }
            else
            {

            }
        }
        msg.reset();


    }
}
void V2xBroker::setSceneOutQueue(V2xSceneMsg::Queue::Ptr &sceneOutQueue)
{
    _scene_out_queue = sceneOutQueue;
}


}

