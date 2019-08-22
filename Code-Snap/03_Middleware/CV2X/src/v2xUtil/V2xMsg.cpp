//
// Created by root on 19-7-11.
//

#include <V2xMsg.h>

#include "V2xMsg.h"

namespace v2x
{
v2x::V2xMsg::e_MsgType v2x::V2xMsg::GetMsgType() const
{
    return m_eMsgType;
}
void v2x::V2xMsg::SetMsgType(v2x::V2xMsg::e_MsgType msgType)
{
    m_eMsgType = msgType;
}
void v2x::V2xMsg::Print()
{
    string info;
    if (m_eMsgType == MSG_TYPE_HV_BSM) {
        info = StrPrinter << "【HV_BSM】"
                          << "\tlatitude:" << u.hvbsm.pos.lat
                          << "\tlongitude:" << u.hvbsm.pos.lon
                          << "\tspeed:" << u.hvbsm.speed
                          << "\theading:" << u.hvbsm.heading
                          << "\t车辆id:" << int(u.hvbsm.id);

    }
    else if (m_eMsgType == MSG_TYPE_RV_BSM) {
        info = StrPrinter << "【RV_BSM】"
                          << "\tlatitude:" << u.rvbsm.pos.lat
                          << "\tlongitude:" << u.rvbsm.pos.lon
                          << "\tspeed:" << u.rvbsm.speed
                          << "\theading:" << u.rvbsm.heading
                          << "\t车辆id:" << int(u.rvbsm.id);
    }

    DebugL << info;

}

}