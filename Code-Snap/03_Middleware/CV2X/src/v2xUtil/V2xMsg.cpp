//
// Created by root on 19-7-11.
//

#include "V2xMsg.h"

namespace v2x
{
v2x::V2xMsg::msg_type_e v2x::V2xMsg::getMsgType() const
{
    return _msg_type;
}
void v2x::V2xMsg::setMsgType(v2x::V2xMsg::msg_type_e msgType)
{
    _msg_type = msgType;
}
void v2x::V2xMsg::Print()
{
    string info;
    if (_msg_type == MSG_TYPE_HV_BSM) {
        info = StrPrinter << "【HV_BSM】"
                          << "\tlatitude:" << u.hvbsm.pos.lat
                          << "\tlongitude:" << u.hvbsm.pos.lon
                          << "\tspeed:" << u.hvbsm.speed
                          << "\theading:" << u.hvbsm.heading
                          << "\t车辆id:" << int(u.hvbsm.id);

    }
    else if (_msg_type == MSG_TYPE_RV_BSM) {
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