/////////////////////////////////////////////////////////
//
// File:
//
// V2xAlgorithmAdapter.h
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

#ifndef CV2X_V2XALGORITHMADAPTER_H
#define CV2X_V2XALGORITHMADAPTER_H
#include "V2xAlgorithmTest.h"
#include "V2xAlgorithmScene.h"
#include "V2xAlgorithm.h"

namespace v2x {

#define Pos2Double(v) (v/100000.0) // deg
#define Heading2Double(v) (v*0.0125)  // deg
#define Speed2Double(v) (v * 0.02 * 3.6) // km/h

class V2xAlgorithmAdapter : public V2xAlgorithm,V2xAlgorithmScene
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
    static bool IsFWCWarning(V2xMsg::Ptr &hv,V2xMsg::Ptr &rv);

    static double Lonlat2dis(V2xMsg::Ptr &hv,V2xMsg::Ptr &rv);

    static Direction RelHeadingJudge(Heading_t hvHeading, Heading_t rvHeading);


};

}



#endif //CV2X_V2XALGORITHMADAPTER_H
