//
// Created by root on 19-8-7.
//

#include <V2xMsg.h>
#include "V2xHvMapSpatCal.h"
#include "V2xMsg.h"
#include "V2xSetting.h"

namespace v2x
{
void V2xHvMapSpatCal::run()
{
    V2xMsg::ValuePtr pMsg;

    while (this->m_pBroker->m_pHvDataQueue->pop(pMsg))
    {
        V2xMsg::e_MsgType tmp_msg_type;
        tmp_msg_type = pMsg->GetMsgType();

        this->m_pBroker->m_pBsmQueue->push(pMsg);

        switch (tmp_msg_type)
        {
        case V2xMsg::MSG_TYPE_HV_BSM:
            this->m_pBroker->m_pHvCurMsg = pMsg;
            if (pMsg->u.hvbsm.speed > 0)
            {
                DebugL << "自车开始动了 speed" <<pMsg->u.hvbsm.speed;
            }
            //DebugL << "HV: Lat=" << pMsg->u.hvbsm.pos.lat << "  Lon=" << pMsg->u.hvbsm.pos.lon;
            break;
        case V2xMsg::MSG_TYPE_MAP:

            break;
        case V2xMsg::MSG_TYPE_SPAT:

            break;
        case V2xMsg::MSG_TYPE_RSM:

            break;
        case V2xMsg::MSG_TYPE_RSI:

            break;
        default:
            break;
        }
    }
}

V2xHvMapSpatCal::V2xHvMapSpatCal(const shared_ptr<V2xBroker> &pBroker)
{
    this->m_pBroker = pBroker;
    this->m_stRsuSize.width = 0;
    this->m_stRsuSize.height = 0;
    this->m_stRsuSize.length = 0;
}

void V2xHvMapSpatCal::HLWarning(V2xMsg::ValuePtr in_pMsg)
{
    DebugL << "Hazardous Location Warning alertType = " << in_pMsg->u.rsi.alertType;
    V2xSceneMsg::ValuePtr scene;
    scene = this->m_pBroker->m_scenePool.obtain();

    scene->setSceneType(V2xSceneMsg::SCENE_TYPE_HLW);
    scene->setAlarmLevel(V2xSceneMsg::ALARM_LEVEL_6);
    scene->assign(StrPrinter <<"道路危险状况预警触发，进程:" << getpid()<< " " <<in_pMsg);
    this->m_pBroker->m_pSceneOutQueue->push(move(scene));
}

void V2xHvMapSpatCal::SLWarning(V2xMsg::ValuePtr in_pMsg)
{
    DebugL << "Speed Limit Warning";
    V2xSceneMsg::ValuePtr scene;

    scene = this->m_pBroker->m_scenePool.obtain();

    scene->setAlarmLevel(V2xSceneMsg::ALARM_LEVEL_6);
    scene->assign(StrPrinter <<"限速预警触发，进程:" << getpid()<< " " <<in_pMsg);
    scene->setSecMark(in_pMsg->u.hvbsm.secMark);
    this->m_pBroker->m_pSceneOutQueue->push(move(scene));
}

void V2xHvMapSpatCal::RLVWarning(V2xMsg::ValuePtr in_pMsg)
{
    DebugL << "Red Light Violation Warning";
    V2xSceneMsg::ValuePtr scene;

    scene = this->m_pBroker->m_scenePool.obtain();

    scene->setAlarmLevel(V2xSceneMsg::ALARM_LEVEL_6);
    scene->assign(StrPrinter <<"闯红灯预警触发，进程:" << getpid()<< " " <<in_pMsg);
    scene->setSecMark(in_pMsg->u.hvbsm.secMark);
    this->m_pBroker->m_pSceneOutQueue->push(move(scene));
}

void V2xHvMapSpatCal::EVWarning(V2xMsg::ValuePtr in_pMsg)
{
    DebugL << "Emergency Vehicle Warning";
    V2xSceneMsg::ValuePtr scene;

    scene = this->m_pBroker->m_scenePool.obtain();

    scene->setAlarmLevel(V2xSceneMsg::ALARM_LEVEL_6);
    scene->assign(StrPrinter <<"紧急车辆预警触发，进程:" << getpid()<< " " <<in_pMsg);
    scene->setSecMark(in_pMsg->u.hvbsm.secMark);
    this->m_pBroker->m_pSceneOutQueue->push(move(scene));
}

void V2xHvMapSpatCal::GLOSA(V2xMsg::ValuePtr in_pMsg)
{
    DebugL << "Green Light Optimal Speed Advisory";
    V2xSceneMsg::ValuePtr scene;

    scene = this->m_pBroker->m_scenePool.obtain();

    scene->setAlarmLevel(V2xSceneMsg::ALARM_LEVEL_6);
    scene->assign(StrPrinter <<"绿波车速引导，进程:" << getpid()<< " " <<in_pMsg);
    scene->setSecMark(in_pMsg->u.hvbsm.secMark);
    this->m_pBroker->m_pSceneOutQueue->push(move(scene));
}

void V2xHvMapSpatCal::IVS(V2xMsg::ValuePtr in_pMsg)
{
    DebugL << "In-Vehicle Signage 车内标牌类型 = " << in_pMsg->u.rsi.alertType;
    V2xSceneMsg::ValuePtr scene;

    scene = this->m_pBroker->m_scenePool.obtain();

    scene->setAlarmLevel(V2xSceneMsg::ALARM_LEVEL_6);
    scene->assign(StrPrinter <<"车内标牌提示，进程:" << getpid()<< " " <<in_pMsg);
    this->m_pBroker->m_pSceneOutQueue->push(move(scene));
}

void V2xHvMapSpatCal::TJWarning(V2xMsg::ValuePtr in_pMsg)
{
    DebugL << "Traffic Jam Warning";
    V2xSceneMsg::ValuePtr scene;

    scene = this->m_pBroker->m_scenePool.obtain();

    scene->setAlarmLevel(V2xSceneMsg::ALARM_LEVEL_6);
    scene->assign(StrPrinter <<"前方拥堵提醒，进程:" << getpid()<< " " <<in_pMsg);
    scene->setSecMark(in_pMsg->u.hvbsm.secMark);
    this->m_pBroker->m_pSceneOutQueue->push(move(scene));
}

V2xHvMapSpatCal::EN_RELATIVE_DIRECTION V2xHvMapSpatCal::GetHVAndRSURelDirection(V2xMsg::ValuePtr in_pHVMsg, V2xMsg::ValuePtr in_pRSUMsg)
{
    V2xHvMapSpatCal::EN_RELATIVE_DIRECTION eRelativeDirection = V2xHvMapSpatCal::RELATIVE_DIRECTION_FRONT;
    return eRelativeDirection;
}

}
