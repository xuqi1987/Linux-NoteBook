/////////////////////////////////////////////////////////
//
// File:
//
// V2xAlgorithm.h
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


class V2xAlgorithm
{
public:
    /**
 * http://blog.sina.com.cn/s/blog_5e7960620101vi0d.html
 * 适用范围：此方法适用于球面上任意两点间的距离求算，用高中数学知识即可证明此方法是球面余弦函数的一个变换，
 * 因为其中换掉了cos项，因此不存在短距离求算时对系统计算精度的过多顾虑的问题。
 * 已知两点经纬度，求两点间距离；Haversine法
 * @param 经纬度使用十进制度，i.e.DDD.DDDDDD°，非度分或度分秒
 * @return cm
 */
    static double Lonlat2dis(double lon1, double lat1, double lon2, double lat2);
    /**
     * 将角度化为弧度后求取距离
     * @param d
     * @return
     */
    static double Rad(double d);
    /**
     * 是否在正前方
     * @param lonlat 经纬度使用十进制度，i.e.DDD.DDDDDD°
     * @param heading 为车辆航向角，即为车头方向与正北方向的顺时针夹角。
     * @return
     */
    static bool IsFront(double lon_hv, double lat_hv,double heading_hv,double lon_rv, double lat_rv);

    /**
     *
     * @param lonlat 经纬度使用十进制度，i.e.DDD.DDDDDD°
     * @param heading_hv为车辆航向角，即为车头方向与正北方向的顺时针夹角。
     * @return
     */
    static bool IsLRrear(double lon_hv, double lat_hv,double heading_hv,double lon_rv, double lat_rv);

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


#endif //CV2X_V2XALGORITHM_H
