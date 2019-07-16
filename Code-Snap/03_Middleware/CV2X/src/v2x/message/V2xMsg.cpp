//
// Created by root on 19-7-11.
//

#include "V2xMsg.h"
uint32_t v2x::V2xBSMMsg::get_temp_id() const
{
    return _temp_id;
}
void v2x::V2xBSMMsg::set_temp_id(uint32_t _temp_id)
{
    V2xBSMMsg::_temp_id = _temp_id;
}
uint32_t v2x::V2xBSMMsg::get_sec_mark() const
{
    return _sec_mark;
}
void v2x::V2xBSMMsg::set_sec_mark(uint32_t _sec_mark)
{
    V2xBSMMsg::_sec_mark = _sec_mark;
}
uint32_t v2x::V2xBSMMsg::get_latitude() const
{
    return _latitude;
}
void v2x::V2xBSMMsg::set_latitude(uint32_t _latitude)
{
    V2xBSMMsg::_latitude = _latitude;
}
uint32_t v2x::V2xBSMMsg::get_longitude() const
{
    return _longitude;
}
void v2x::V2xBSMMsg::set_longitude(uint32_t _longitude)
{
    V2xBSMMsg::_longitude = _longitude;
}
uint32_t v2x::V2xBSMMsg::get_elevation() const
{
    return _elevation;
}
void v2x::V2xBSMMsg::set_elevation(uint32_t _elevation)
{
    V2xBSMMsg::_elevation = _elevation;
}
uint32_t v2x::V2xBSMMsg::get_transmission_state() const
{
    return _transmission_state;
}
void v2x::V2xBSMMsg::set_transmission_state(uint32_t _transmission_state)
{
    V2xBSMMsg::_transmission_state = _transmission_state;
}
uint32_t v2x::V2xBSMMsg::get_speed() const
{
    return _speed;
}
void v2x::V2xBSMMsg::set_speed(uint32_t _speed)
{
    V2xBSMMsg::_speed = _speed;
}
uint32_t v2x::V2xBSMMsg::get_heading() const
{
    return _heading;
}
void v2x::V2xBSMMsg::set_heading(uint32_t _heading)
{
    V2xBSMMsg::_heading = _heading;
}
uint32_t v2x::V2xCANMsg::get_speed() const
{
    return _speed;
}
void v2x::V2xCANMsg::set_speed(uint32_t _speed)
{
    V2xCANMsg::_speed = _speed;
}
uint32_t v2x::V2xGNSSMsg::get_latitude() const
{
    return _latitude;
}
void v2x::V2xGNSSMsg::set_latitude(uint32_t _latitude)
{
    V2xGNSSMsg::_latitude = _latitude;
}
uint32_t v2x::V2xGNSSMsg::get_longitude() const
{
    return _longitude;
}
void v2x::V2xGNSSMsg::set_longitude(uint32_t _longitude)
{
    V2xGNSSMsg::_longitude = _longitude;
}
uint32_t v2x::V2xGNSSMsg::get_altitude() const
{
    return _altitude;
}
void v2x::V2xGNSSMsg::set_altitude(uint32_t _altitude)
{
    V2xGNSSMsg::_altitude = _altitude;
}
uint32_t v2x::V2xGNSSMsg::get_speed() const
{
    return _speed;
}
void v2x::V2xGNSSMsg::set_speed(uint32_t _speed)
{
    V2xGNSSMsg::_speed = _speed;
}
uint32_t v2x::V2xGNSSMsg::get_heading() const
{
    return _heading;
}
void v2x::V2xGNSSMsg::set_heading(uint32_t _heading)
{
    V2xGNSSMsg::_heading = _heading;
}
