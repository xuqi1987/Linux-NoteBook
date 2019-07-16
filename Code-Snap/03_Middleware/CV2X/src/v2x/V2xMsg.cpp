//
// Created by root on 19-7-11.
//

#include "V2xMsg.h"
uint32_t v2x::V2xBSMMsg::getTempId() const
{
    return _temp_id;
}
void v2x::V2xBSMMsg::setTempId(uint32_t tempId)
{
    _temp_id = tempId;
}
uint32_t v2x::V2xBSMMsg::getSecMark() const
{
    return _sec_mark;
}
void v2x::V2xBSMMsg::setSecMark(uint32_t secMark)
{
    _sec_mark = secMark;
}
uint32_t v2x::V2xBSMMsg::getLatitude() const
{
    return _latitude;
}
void v2x::V2xBSMMsg::setLatitude(uint32_t latitude)
{
    _latitude = latitude;
}
uint32_t v2x::V2xBSMMsg::getLongitude() const
{
    return _longitude;
}
void v2x::V2xBSMMsg::setLongitude(uint32_t longitude)
{
    _longitude = longitude;
}
uint32_t v2x::V2xBSMMsg::getElevation() const
{
    return _elevation;
}
void v2x::V2xBSMMsg::setElevation(uint32_t elevation)
{
    _elevation = elevation;
}
uint32_t v2x::V2xBSMMsg::getTransmissionState() const
{
    return _transmission_state;
}
void v2x::V2xBSMMsg::setTransmissionState(uint32_t transmissionState)
{
    _transmission_state = transmissionState;
}
uint32_t v2x::V2xBSMMsg::getSpeed() const
{
    return _speed;
}
void v2x::V2xBSMMsg::setSpeed(uint32_t speed)
{
    _speed = speed;
}
uint32_t v2x::V2xBSMMsg::getHeading() const
{
    return _heading;
}
void v2x::V2xBSMMsg::setHeading(uint32_t heading)
{
    _heading = heading;
}
uint32_t v2x::V2xCANMsg::getSpeed() const
{
    return _speed;
}
void v2x::V2xCANMsg::setSpeed(uint32_t speed)
{
    _speed = speed;
}
uint32_t v2x::V2xCANMsg::getSteerWhlAngle() const
{
    return _steer_whl_angle;
}
void v2x::V2xCANMsg::setSteerWhlAngle(uint32_t steerWhlAngle)
{
    _steer_whl_angle = steerWhlAngle;
}
uint32_t v2x::V2xCANMsg::getEngineStatus() const
{
    return _engine_status;
}
void v2x::V2xCANMsg::setEngineStatus(uint32_t engineStatus)
{
    _engine_status = engineStatus;
}
uint32_t v2x::V2xGNSSMsg::getLatitude() const
{
    return _latitude;
}
void v2x::V2xGNSSMsg::setLatitude(uint32_t latitude)
{
    _latitude = latitude;
}
uint32_t v2x::V2xGNSSMsg::getLongitude() const
{
    return _longitude;
}
void v2x::V2xGNSSMsg::setLongitude(uint32_t longitude)
{
    _longitude = longitude;
}
uint32_t v2x::V2xGNSSMsg::getAltitude() const
{
    return _altitude;
}
void v2x::V2xGNSSMsg::setAltitude(uint32_t altitude)
{
    _altitude = altitude;
}
uint32_t v2x::V2xGNSSMsg::getSpeed() const
{
    return _speed;
}
void v2x::V2xGNSSMsg::setSpeed(uint32_t speed)
{
    _speed = speed;
}
uint32_t v2x::V2xGNSSMsg::getHeading() const
{
    return _heading;
}
void v2x::V2xGNSSMsg::setHeading(uint32_t heading)
{
    _heading = heading;
}
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
                          << "\tlatitude:" << u.hvbsm.getLatitude()
                          << "\tlongitude:" << u.hvbsm.getLongitude()
                          << "\tspeed:" << u.hvbsm.getSpeed()
                          << "\theading:" << u.hvbsm.getHeading()
                          << "\t车辆id:" << u.hvbsm.getTempId();

    }
    else if (_msg_type == MSG_TYPE_RV_BSM) {
        info = StrPrinter << "【RV_BSM】"
                          << "\tlatitude:" << u.rvbsm.getLatitude()
                          << "\tlongitude:" << u.rvbsm.getLongitude()
                          << "\tspeed:" << u.rvbsm.getSpeed()
                          << "\theading:" << u.rvbsm.getHeading()
                          << "\t车辆id:" << u.rvbsm.getTempId();
    }
    else if (_msg_type == MSG_TYPE_GNSS) {
        info = StrPrinter << "【GNSS】"
                          << "\tlatitude:" << u.hvgnss.getLatitude()
                          << "\tlongitude:" << u.hvgnss.getLongitude()
                          << "\tspeed:" << u.hvgnss.getSpeed()
                          << "\theading:" << u.hvgnss.getHeading();
    }
    else if (_msg_type == MSG_TYPE_CAN) {
        info = StrPrinter << "【CAN】"
                          << "\tspeed:" << u.hvcan.getSpeed()
                          << "\tsteer_whl_angle:" << u.hvcan.getSteerWhlAngle()
                          << "\tengine_status:" << u.hvcan.getEngineStatus();

    }
    DebugL << info;

}
