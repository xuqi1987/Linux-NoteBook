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
    uint32_t get_temp_id() const;
    void set_temp_id(uint32_t _temp_id);
    uint32_t get_sec_mark() const;
    void set_sec_mark(uint32_t _sec_mark);
    uint32_t get_latitude() const;
    void set_latitude(uint32_t _latitude);
    uint32_t get_longitude() const;
    void set_longitude(uint32_t _longitude);
    uint32_t get_elevation() const;
    void set_elevation(uint32_t _elevation);
    uint32_t get_transmission_state() const;
    void set_transmission_state(uint32_t _transmission_state);
    uint32_t get_speed() const;
    void set_speed(uint32_t _speed);
    uint32_t get_heading() const;
    void set_heading(uint32_t _heading);
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

private:
    uint32_t _speed;
    uint32_t _steer_whl_angle;
    uint32_t _engine_status;

public:
    uint32_t get_speed() const;
    void set_speed(uint32_t _speed);

};

class V2xGNSSMsg
{

public:
    uint32_t get_latitude() const;
    void set_latitude(uint32_t _latitude);
    uint32_t get_longitude() const;
    void set_longitude(uint32_t _longitude);
    uint32_t get_altitude() const;
    void set_altitude(uint32_t _altitude);
    uint32_t get_speed() const;
    void set_speed(uint32_t _speed);
    uint32_t get_heading() const;
    void set_heading(uint32_t _heading);
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
    template<typename ...ArgTypes>
    V2xMsg(ArgTypes &&...args)
        : string(std::forward<ArgTypes>(args)...)
    {
        DebugL << "创建V2xMsg对象:" << this << " " << *this;
    };

    ~V2xMsg()
    {
        WarnL << "销毁V2xMsg对象:" << this << " " << *this;
    };

    typedef enum
    {
        MSG_TYPE_HV_BSM = 1,
        MSG_TYPE_RV_BSM = 2,
        MSG_TYPE_CAN = 3,
        MSG_TYPE_GNSS = 4,
        MSG_TYPE_MAX,
    } msg_type_e;


public:
    msg_type_e get_msg_type() const
    {
        return _msg_type;
    }
    void set_msg_type(msg_type_e _msg_type)
    {
        V2xMsg::_msg_type = _msg_type;
    }

    union
    {
        V2xBSMMsg   _hvbsm; // HV BSM data
        V2xBSMMsg   _rvbsm; // RV BSM data
        V2xGNSSMsg  _hvgnss;
        V2xCANMsg   _hvcan;

    } bsm;

private:
    msg_type_e _msg_type;
};

}


#endif //CV2X_V2XCAR_H
