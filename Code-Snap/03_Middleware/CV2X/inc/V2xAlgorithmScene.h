/////////////////////////////////////////////////////////
//
// File:
//
// V2xAlgorithmScene.h
//
// Purpose
//
// <Describe here the purpose of the file>
// Ex:
// Definition of the String class
//
// File revision history:
//
// <comply with the configuration management system, or
// follow the following template:
// Date:
// Reason of change: create 1st version
// root
//
// Copyright Yanfeng Visteon Electronics Co.,Ltd
/////////////////////////////////////////////////////////

//
// Created by root on 19-8-23.
//

#ifndef CV2X_V2XALGORITHMSCENE_H
#define CV2X_V2XALGORITHMSCENE_H

#include "V2xAlgorithmTest.h"

namespace v2x {

class V2xAlgorithmScene
{
public:
    /**
 * 根据TTC来判断FCW是否触发
 * 1. 车速>= 15 km/h 时，同车道上同向行驶预计 3S 后将发生碰撞时给用户预警
 * 2. 车速>=60km/h 时，同车道上与前车距离<= 3m 时给用户预警
 * 3. 15km/h > 车速 > 2km/h 时，同车道上与前车距离<= 0.5 M 时给用户预警
 * @param lonlat 经纬度使用十进制度，i.e.DDD.DDDDDD°
 * @param heading 为车辆航向角，即为车头方向与正北方向的顺时针夹角。
 * @param speed km/h
 * @return
 */
    static bool IsFWCWarning(double lon_hv, double lat_hv,double heading_hv,double speed_hv, double lon_rv, double lat_rv,double heading_rv,double speed_rv);
};


}



#endif //CV2X_V2XALGORITHMSCENE_H
