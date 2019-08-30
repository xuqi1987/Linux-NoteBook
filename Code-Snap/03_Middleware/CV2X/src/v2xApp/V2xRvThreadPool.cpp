//
// Created by xuqi on 2019-08-07.
//

#include <V2xMsg.h>
#include "V2xRvThreadPool.h"
#include "V2xAlgorithmAdapter.h"

namespace v2x {

void V2xRvThreadPool::Run(int iIndex)
{
    V2xMsg::ValuePtr rv_msg;
    V2xMsg::ValuePtr hv_msg;
    V2xSceneMsg::ValuePtr scene;

    Ticker ticker;

    while (this->m_pBroker->m_pRvDataQueue->pop(rv_msg))
    {
        hv_msg = this->m_pBroker->m_pHvCurMsg;

        if(hv_msg)
        {
           // DebugL << "V2V 场景获取最新自车BSM消息";
            //WarnL << "HV: Lat=" << hv_msg->u.hvbsm.pos.lat << "  Lon=" << hv_msg->u.hvbsm.pos.lon;
            WarnL << "Distance:" << V2xAlgorithmAdapter::GetDistance(hv_msg->u.hvbsm, rv_msg->u.rvbsm) /100.0 << "m\t"
                <<"H Speed "<< Speed2Double(hv_msg->u.hvbsm.speed) << "km/h\t"
                <<"R Speed " << Speed2Double(rv_msg->u.rvbsm.speed)<< "km/h\t"
                <<"H Heading "<< Heading2Double(hv_msg->u.hvbsm.heading) << "deg\t"
                <<"R Heading " << Heading2Double(rv_msg->u.rvbsm.heading)<< "deg\t";

        }

        //用于测试算法的性能
        ticker.resetTime();

        rv_msg.reset();

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
