
#ifndef V2XALGORITHM_H
#define V2XALGORITHM_H
#include <stdint.h>
#include "V2xMsg.h"

namespace v2x {

#define EARTH_RADIUS	6371.004 // the earth radius km
#define PI				(3.14159265358979323846264338327950288419717) //this macro is aim to control the putty log when release.
class V2xAlgorithm
{
public:
    /**https://blog.csdn.net/superrunner_wujin/article/details/79974661
     * 已知两点经纬度，求两点间距离；Haversine法
     * @param lonlat 1/10 micro degree
     * @return m unit
     */
    static double Lonlat2dis(Longitude_t lon1, Latitude_t lat1, Longitude_t lon2, Latitude_t lat2);
    /**
     * 已知两点经纬度，求两点间距离；Haversine法
     * @param 经纬度使用十进制度，i.e.DDD.DDDDDD°，非度分或度分秒
     * @return
     */
    static double Lonlat2dis(double lon1, double lat1, double lon2, double lat2);
    /**
     * 将角度化为弧度后求取距离
     * @param d
     * @return
     */
    static double Rad(double d);
};

}

#endif //V2XALGORITHM_H
