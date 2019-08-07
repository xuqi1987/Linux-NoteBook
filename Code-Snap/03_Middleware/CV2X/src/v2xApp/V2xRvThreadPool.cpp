//
// Created by xuqi on 2019-08-07.
//

#include "V2xRvThreadPool.h"

namespace v2x {

void V2xRvThreadPool::run(int num)
{
    V2xMsg::ValuePtr msg;
    V2xSceneMsg::ValuePtr scene;

    Ticker ticker;
    while (this->_broker->_rv_data_queue->pop(msg))
    {

        //用于测试算法的性能
        ticker.resetTime();

        DebugL << "模拟场景判断,如果车辆ID小于5，触发场景:" << msg;

        if (msg->u.rvbsm.id< 5)
        {
            scene = this->_broker->_scene_pool.obtain();

            if(msg->u.rvbsm.id== 1)
            {
                scene->setLevel(V2xSceneMsg::LEVEL_1);
                scene->assign(StrPrinter <<"高优先级 场景触发，进程:" << getpid()<< " " <<msg );
                scene->setSecMark(msg->u.rvbsm.secMark);
                this->_broker->_scene_out_queue->push(scene);
            }
            else if (msg->u.rvbsm.id== 2)
            {
                scene->setLevel(V2xSceneMsg::LEVEL_2);
                scene->setSecMark(msg->u.rvbsm.secMark);
                scene->assign(StrPrinter <<"中优先级 场景触发，进程:" << getpid()<< " " <<msg);
                this->_broker->_scene_out_queue->push(scene);
            }
            else if (msg->u.rvbsm.id== 3)
            {
                scene->setLevel(V2xSceneMsg::LEVEL_3);
                scene->setSecMark(msg->u.rvbsm.secMark);
                scene->assign(StrPrinter <<"低优先级 场景触发，进程:" << getpid()<< " " <<msg);
                this->_broker->_scene_out_queue->push(scene);
            }
            else
            {

            }
        }
        msg.reset();

        TraceL << "V2xRvThreadPool "<<num <<"耗时ms:" << ticker.elapsedTime();
        ticker.resetTime();
    }
}
V2xRvThreadPool::V2xRvThreadPool(const shared_ptr<V2xBroker> &broker,int threadnum)
:V2xThreadPool(threadnum)
{
    this->_broker = broker;
}

}