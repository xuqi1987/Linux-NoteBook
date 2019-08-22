//
// Created by xuqi on 2019-08-07.
//

#include "V2xRvThreadPool.h"

namespace v2x {

void V2xRvThreadPool::Run(int iIndex)
{
    V2xMsg::ValuePtr msg;
    V2xMsg::ValuePtr hv_msg;
    V2xSceneMsg::ValuePtr scene;

    Ticker ticker;

    while (this->m_pBroker->m_pRvDataQueue->pop(msg))
    {
        hv_msg = this->m_pBroker->m_pHvCurMsg;
        if(hv_msg)
        {
            DebugL << "V2V 场景获取最新自车BSM消息";
            DebugL << "V2V Sence HV: Lat=" << hv_msg->u.hvbsm.pos.lat << "  Lon=" << hv_msg->u.hvbsm.pos.lon;
        }

        //用于测试算法的性能
        ticker.resetTime();

        DebugL << "模拟场景判断,如果车辆ID小于5，触发场景:" << msg;

        if (msg->u.rvbsm.id< 5)
        {
            scene = this->m_pBroker->m_scenePool.obtain();

            if(msg->u.rvbsm.id== 1)
            {
                scene->setLevel(V2xSceneMsg::LEVEL_1);
                scene->assign(StrPrinter <<"高优先级 场景触发，进程:" << getpid()<< " " <<msg );
                scene->setSecMark(msg->u.rvbsm.secMark);
                this->m_pBroker->m_pSceneOutQueue->push(move(scene));
            }
            else if (msg->u.rvbsm.id== 2)
            {
                scene->setLevel(V2xSceneMsg::LEVEL_2);
                scene->setSecMark(msg->u.rvbsm.secMark);
                scene->assign(StrPrinter <<"中优先级 场景触发，进程:" << getpid()<< " " <<msg);
                this->m_pBroker->m_pSceneOutQueue->push(move(scene));
            }
            else if (msg->u.rvbsm.id== 3)
            {
                scene->setLevel(V2xSceneMsg::LEVEL_3);
                scene->setSecMark(msg->u.rvbsm.secMark);
                scene->assign(StrPrinter <<"低优先级 场景触发，进程:" << getpid()<< " " <<msg);
                this->m_pBroker->m_pSceneOutQueue->push(move(scene));
            }
            else
            {

            }
        }
        msg.reset();

        TraceL << "V2xRvThreadPool "<<iIndex <<"耗时ms:" << ticker.elapsedTime();
        ticker.resetTime();
    }
}
V2xRvThreadPool::V2xRvThreadPool(const shared_ptr<V2xBroker> &pBroker,int iThreadnum)
:V2xThreadPool(iThreadnum)
{
    this->m_pBroker = pBroker;
}

}
