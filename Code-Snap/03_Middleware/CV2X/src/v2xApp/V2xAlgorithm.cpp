//
// Created by root on 19-8-23.
//

#include "V2xAlgorithm.h"

namespace v2x {


double V2xAlgorithm::Rad(double d)
{
    return d * PI / 180.0;
}

double V2xAlgorithm::Lonlat2dis(double lon1, double lat1, double lon2, double lat2)
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


V2xAlgorithm::Direction V2xAlgorithm::RelHeadingJudge(double hvHeading, double rvHeading)
{
    // 相对航向角Theta
    double theta = 0.0;
    if (rvHeading >= hvHeading)
    {
        theta = rvHeading - hvHeading;
    }
    else
    {
        theta =  rvHeading - hvHeading + 360;
    }

    // Theta = 0~15 or 345~360:  %二车同向行驶
    if ((theta >= 0 && theta < 15)
    || (theta > 345 && theta <= 360))
    {
        return Direction_Same;
    }
    // Theta = 165~195：
    else if (theta > 165 && theta < 195)
    {
        return Direction_Reverse;
    }
    else
    {
        return Direction_Cross;
    }

}
void V2xAlgorithm::CoordinateChange(double hvLon,
                                    double hvLat,
                                    double rvLon,
                                    double rvLat,
                                    double hvTheta,
                                    V2xAlgorithm::RelPosPoints_t &relPos)
{
    // 根据经纬度信息计算X方向（东西，东为正）、Y方向（南北，北为正）上两车相对距离
    // 利用Haversine法，参考https://blog.csdn.net/superrunner_wujin/article/details/79974661
    // X' = 2*R*arcsin(cos(RV_lati)*sin((RV_longi-HV_longi)/2))	%R：地球半径
    double x = 2 * EARTH_RADIUS * asin(cos(rvLat)) * sin((rvLon - hvLon)/2.0);
    //  Y' = R*(RV_lati-HV_lati)%将经纬度坐标转化为RV与HV在正北和正东方向上的相对距离
    double y = EARTH_RADIUS * (rvLat - hvLat);
    relPos.y = cos(hvTheta) * y + sin(hvTheta) * x;
    relPos.x = -sin(hvTheta)*y + cos(hvTheta) * x;
}

V2xAlgorithm::RelPos V2xAlgorithm::RvRelPosition(V2xAlgorithm::RelPosPoints_t &rvPos,
                                                 double dHvWidth,
                                                 double dRvWidth,
                                                 double dHvConf,
                                                 double dRvConf)
{
    return RelPos_RFront;
}



}

