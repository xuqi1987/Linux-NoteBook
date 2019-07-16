//
// Created by root on 19-7-11.
//

#ifndef CV2X_V2XCAR_H
#define CV2X_V2XCAR_H
#include <string>
#include "Util/Logger.h"

using namespace std;
using namespace toolkit;

namespace v2x
{

// id
// E_DSecond 时间戳
// DF_Position3D
// DE_PositionConfidence  车辆经纬度
// DE_ElevationConfidence 车辆高度
// DE_TransmissionState 档位信息
// DE_Speed 车速
// DE_Heading 车头方向
// DF_AccelerationSet4Way 四轴加速度，横纵垂摆
// DF_BrakeSystemStatus 车身刹车系统 车轮，脚踏板，abs..
// DF_VehicleSize 车身大小
class V2xBSMMsg
{

public:
    uint32_t getTempId() const;
    void setTempId(uint32_t tempId);
    uint32_t getSecMark() const;
    void setSecMark(uint32_t secMark);
    uint32_t getLatitude() const;
    void setLatitude(uint32_t latitude);
    uint32_t getLongitude() const;
    void setLongitude(uint32_t longitude);
    uint32_t getElevation() const;
    void setElevation(uint32_t elevation);
    uint32_t getTransmissionState() const;
    void setTransmissionState(uint32_t transmissionState);
    uint32_t getSpeed() const;
    void setSpeed(uint32_t speed);
    uint32_t getHeading() const;
    void setHeading(uint32_t heading);
private:
    uint32_t _temp_id;
    uint32_t _sec_mark;
    uint32_t _latitude;
    uint32_t _longitude;
    uint32_t _elevation;
    uint32_t _transmission_state;
    uint32_t _speed;
    uint32_t _heading;
};

class V2xCANMsg
{
public:
    uint32_t getSpeed() const;
    void setSpeed(uint32_t speed);
    uint32_t getSteerWhlAngle() const;
    void setSteerWhlAngle(uint32_t steerWhlAngle);
    uint32_t getEngineStatus() const;
    void setEngineStatus(uint32_t engineStatus);
private:
    uint32_t _speed;
    uint32_t _steer_whl_angle;
    uint32_t _engine_status;

};

class V2xGNSSMsg
{

public:
    uint32_t getLatitude() const;
    void setLatitude(uint32_t latitude);
    uint32_t getLongitude() const;
    void setLongitude(uint32_t longitude);
    uint32_t getAltitude() const;
    void setAltitude(uint32_t altitude);
    uint32_t getSpeed() const;
    void setSpeed(uint32_t speed);
    uint32_t getHeading() const;
    void setHeading(uint32_t heading);

private:
    uint32_t _latitude;
    uint32_t _longitude;
    uint32_t _altitude;
    uint32_t _speed;
    uint32_t _heading;
};

class V2xMsg: public string
{
public:
    typedef shared_ptr<V2xMsg> Ptr;

    typedef enum
    {
        MSG_TYPE_HV_BSM = 1,
        MSG_TYPE_RV_BSM = 2,
        MSG_TYPE_CAN = 3,
        MSG_TYPE_GNSS = 4,
        MSG_TYPE_MAX,
    } msg_type_e;

    union
    {
        V2xBSMMsg hvbsm; // HV BSM data
        V2xBSMMsg rvbsm; // RV BSM data
        V2xGNSSMsg hvgnss;
        V2xCANMsg hvcan;

    } u;

    template<typename ...ArgTypes>
    V2xMsg(ArgTypes &&...args)
        : string(std::forward<ArgTypes>(args)...)
    {
        TraceL << "创建V2xMsg对象:" << this << " " << *this;
    };

    ~V2xMsg()
    {
        WarnL << "销毁V2xMsg对象:" << this << " " << *this;
    };

    void Print();
    msg_type_e getMsgType() const;
    void setMsgType(msg_type_e msgType);

private:
    msg_type_e _msg_type;
};

}

#endif //CV2X_V2XCAR_H
