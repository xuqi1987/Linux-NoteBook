/////////////////////////////////////////////////////////
//
// File:
//
// V2xAlgorithmTest.h
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

#ifndef CV2X_V2XALGORITHM_H
#define CV2X_V2XALGORITHM_H
#include "V2xMsg.h"

namespace  v2x {


/*
地球半径:赤道半径 = 6378.140 公里
极半径 = 6356.755 公里
平均半径 = 6371.004 公里
 */
#define EARTH_RADIUS	6371004 // the earth radius km
#define PI				(3.14159265358979323846264338327950288419717) //this macro is aim to control the putty log when release.

class V2xAlgorithmTest
{
public:

    typedef enum Direction{
        Direction_Same = 0, // 同向
        Direction_Reverse,  // 对向
        Direction_Cross,    // 交叉
    }e_Direction;

    typedef enum RelPos {
        RelPos_Front,
        RelPos_RFront,
        RelPos_LFront,
        RelPos_Back,
        RelPos_RBack,
        RelPos_LBack,
    }e_RelPos;

    typedef struct RelPosPoints {
        double x;
        double y;
    }RelPosPoints_t;

    /**
     * http://blog.sina.com.cn/s/blog_5e7960620101vi0d.html
     * 适用范围：此方法适用于球面上任意两点间的距离求算，用高中数学知识即可证明此方法是球面余弦函数的一个变换，
     * 因为其中换掉了cos项，因此不存在短距离求算时对系统计算精度的过多顾虑的问题。
     * 已知两点经纬度，求两点间距离；Haversine法
     * @param 经纬度使用十进制度，i.e.DDD.DDDDDD°，非度分或度分秒
     * @return m X.XX m
     */
    static double GetDistance(double lon1, double lat1, double lon2, double lat2);
    /**
     * 将角度化为弧度后求取距离 0~360 0~2Pi
     * @param d
     * @return
     */
    static double Rad(double d);

    /**
     * 相对航向判断函数(HV航向角,RV航向角):
     * @param hvHeading deg
     * @return 同向/对向/交叉
     */
    static Direction RelHeadingJudge(double hvHeading, double rvHeading);

    /**
     * 坐标变换 根据经纬度信息计算X方向（东西，东为正）、Y方向（南北，北为正）上两车相对距离
     * @param hvLon deg
     * @param hvLat
     * @param rvLon
     * @param rvLat
     * @param hvHeading
     */
    static void GetXYDistance(double hvLon,
                              double hvLat,
                              double rvLon,
                              double rvLat,
                              double hvHeading,
                              RelPosPoints_t &relPos);

    /**
     * RV相对方位确定
     * @param rvPos 以自车为中心的RV位置 调用CoordinateChange计算的值
     * @param dHvWidth 自车宽度 m
     * @param dRvWidth 他车宽度 m
     * @param dHvConf 自车经纬度精度 m
     * @param dRvConf 他车经纬度的精度 m
     * @return
     */
    static RelPos RvRelPosition(RelPosPoints_t &rvPos,double dHvWidth,double dRvWidth, double dHvConf = 0.0, double dRvConf = 0.0);

private:

};

}


#endif //CV2X_V2XALGORITHM_H
