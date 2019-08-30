//
// Created by root on 19-8-23.
//

#include "V2xAlgorithmTest.h"
#include <cmath>
#include <V2xAlgorithmTest.h>


namespace v2x
{


double V2xAlgorithmTest::Rad(double d)
{
    return d * PI / 180.0;
}

double V2xAlgorithmTest::GetDistance(double lon1, double lat1, double lon2, double lat2)
{

    double radLat1 = Rad(lat1);
    double radLat2 = Rad(lat2);
    double a = radLat1 - radLat2;
    double b = Rad(lon1) - Rad(lon2);

    //Haversine法
    double s = 2 * asin(sqrt(pow(sin(a / 2), 2) + cos(radLat1) * cos(radLat2) * pow(sin(b / 2), 2)));
    s = s * EARTH_RADIUS;
    //四舍五入到最邻近的整数
    s = round(s * 100) / 100;

    return s;
}


V2xAlgorithmTest::Direction V2xAlgorithmTest::RelHeadingJudge(double hvHeading, double rvHeading)
{
    // 相对航向角Theta
    double theta = 0.0;
    if (rvHeading >= hvHeading) {
        theta = rvHeading - hvHeading;
    }
    else {
        theta = rvHeading - hvHeading + 360;
    }

    // Theta = 0~15 or 345~360:  %二车同向行驶
    if ((theta >= 0 && theta < 15)
        || (theta > 345 && theta <= 360)) {
        return Direction_Same;
    }
        // Theta = 165~195：
    else if (theta > 165 && theta < 195) {
        return Direction_Reverse;
    }
    else {
        return Direction_Cross;
    }

}
void V2xAlgorithmTest::GetXYDistance(double hvLon,
                                 double hvLat,
                                 double rvLon,
                                 double rvLat,
                                 double hvHeading,
                                 V2xAlgorithmTest::RelPosPoints_t &relPos)
{
    double radhvLon = Rad(hvLon);
    double radhvLat = Rad(hvLat);
    double radrvLon = Rad(rvLon);
    double radrvLat = Rad(rvLat);
    double radhvTheta = Rad(hvHeading);

    // 根据经纬度信息计算X方向（东西，东为正）、Y方向（南北，北为正）上两车相对距离
    double x = 2 * EARTH_RADIUS * asin(cos(radrvLat) * sin((radrvLon - radhvLon) / 2.0));
    double y = EARTH_RADIUS * (radrvLat - radhvLat);

    relPos.y = cos(radhvTheta) * y + sin(radhvTheta) * x;
    relPos.x = -sin(radhvTheta) * y + cos(radhvTheta) * x;

    relPos.y = round(relPos.y * 100) / 100;
    relPos.x = round(relPos.x * 100) / 100;
}

V2xAlgorithmTest::RelPos V2xAlgorithmTest::RvRelPosition(V2xAlgorithmTest::RelPosPoints_t &rvPos,
                                                 double dHvWidth,
                                                 double dRvWidth,
                                                 double dHvConf,
                                                 double dRvConf)
{
    double x = rvPos.x;
    double y = rvPos.y;

    double t = 0.5 * (dHvWidth + dRvWidth + dHvConf + dRvConf);
    if (y > 0) {
        //  X 介于 ±0.5*(HV车宽 + RV车宽 + HV位置精度 + RV位置精度)
        if (x > t) {
            return RelPos::RelPos_RFront;
        }
        else if (x < -t) {
            return RelPos::RelPos_LFront;
        }
        else {
            return RelPos::RelPos_Front;
        }
    }
    else {
        if (x > t) {
            return RelPos::RelPos_RBack;
        }
        else if (x < -t) {
            return RelPos::RelPos_LBack;
        }
        else {
            return RelPos::RelPos_Back;
        }
    }
}


}

