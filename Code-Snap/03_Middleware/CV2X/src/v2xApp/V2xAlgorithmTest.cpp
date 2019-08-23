//
// Created by xuqi on 2019-07-17.
//

#include <cmath>
#include <V2xAlgorithmTest.h>

#include "V2xAlgorithmTest.h"

namespace v2x
{

double V2xAlgorithmTest::Rad(double d)
{
    return d * PI / 180.0;
}

double V2xAlgorithmTest::Lonlat2dis(double lon1, double lat1, double lon2, double lat2)
{

    double radLat1 = Rad(lat1);
    double radLat2 = Rad(lat2);
    double a = radLat1 - radLat2;
    double b = Rad(lon1) - Rad(lon2);

    //Haversine法
    double s = 2 * asin(sqrt(pow(sin(a / 2), 2) + cos(radLat1) * cos(radLat2) * pow(sin(b / 2), 2)));
    s = s * EARTH_RADIUS;
    //四舍五入到最邻近的整数
    s = round(s * 10000.0) * 10;

    return s;
}
bool V2xAlgorithmTest::IsFront(double lon_hv, double lat_hv, double heading_hv, double lon_rv, double lat_rv)
{

    // 弧长向弧度的转换
    double angle_hv = (450-heading_hv)/180* PI;
    double delta_lon = lon_rv - lon_hv;
    double delta_lat = lat_rv - lat_hv;
    // 水平坐标分量
    double para = cos(angle_hv)* delta_lon + sin(angle_hv)*delta_lat;
    // 正交经纬度差
    double orth_dis = 1000 * Lonlat2dis(lon_hv,lat_hv,lon_hv + (delta_lon-para*cos(angle_hv)),lat_hv + (delta_lat-para*sin(angle_hv)));

    if ((para>0.0) && (orth_dis<4.5)) //orth_dis<4.5 depends on vehicle size
    {
        return true;
    }
    return false;
}
bool V2xAlgorithmTest::IsLRrear(double lon_hv, double lat_hv, double heading_hv, double lon_rv, double lat_rv)
{
    // 弧长向弧度的转换
    double angle_hv = (450-heading_hv)/180* PI;
    double delta_lon = lon_rv - lon_hv;
    double delta_lat = lat_rv - lat_hv;
    // 水平坐标分量
    double para = cos(angle_hv)* delta_lon + sin(angle_hv)*delta_lat;
    // 正交经纬度差
    double orth_dis = 1000 * Lonlat2dis(lon_hv,lat_hv,lon_hv + (delta_lon-para*cos(angle_hv)),lat_hv + (delta_lat-para*sin(angle_hv)));

    if ((para < 0.0) &&(orth_dis >4.5)) //orth_dis<4.5 depends on vehicle size
    {
        return true;
    }
    return false;

}
double V2xAlgorithmTest::CalVecicleTTC(double lon_hv,
                                       double lat_hv,
                                       double heading_hv,
                                       double speed_hv,
                                       double lon_rv,
                                       double lat_rv,
                                       double heading_rv,
                                       double speed_rv)
{
    double delta_lon = lon_rv - lon_hv;
    double delta_lat = lat_rv - lat_hv;
    double angle_hv = (450-heading_hv)/180* PI;
    double angle_rv = (450-heading_rv)/180* PI;

    double delta_position_lon = delta_lon * PI * EARTH_RADIUS * 1000.0/180.0;// 单位：m
    double delta_position_lat = delta_lat * PI * EARTH_RADIUS * 1000.0/180.0; //单位：m

    double delta_speed_lon = (speed_hv * cos(angle_hv) - speed_rv* cos(angle_rv))/3.6; //单位:m/s
    double delta_speed_lat = (speed_hv * sin(angle_hv) - speed_rv* sin(angle_rv))/3.6; //单位:m/s

    double a = delta_position_lon * delta_speed_lon + delta_position_lat * delta_speed_lat; // sum(delta_position.*delta_speed)

    double b = sqrt(pow(delta_speed_lon,2) + pow (delta_speed_lat,2)); // norm(delta_speed)

    // ttc = -1*sum(delta_position.*delta_speed)/norm(delta_speed)/norm(delta_speed);
    double ttc = -1 * a /b /b;
    std::cout << "碰撞时间:" << ttc << "s" <<std::endl;
    return ttc;
}

}
