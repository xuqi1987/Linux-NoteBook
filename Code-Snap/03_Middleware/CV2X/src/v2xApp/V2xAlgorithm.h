//
// Created by xuqi on 2019-07-17.
//

#ifndef V2XALGORITHM_H
#define V2XALGORITHM_H
#include <math.h>
#include <cstdint>
#include "v2xFacility/V2xMsg.h"

namespace v2x {

const double PI = 3.1415926;

class V2xAlgorithm
{
public:

    static double lonlat2dis(V2xBSMMsg &bsm1,V2xBSMMsg &bsm2);
    static bool   isLRrear(V2xBSMMsg &bsm1,V2xBSMMsg &bsm2);
    static bool   isFront(V2xBSMMsg &bsm1,V2xBSMMsg &bsm2);
private:

    // 计算两点的距离
    static double lonlat2dis(Longitude_t lon1, Latitude_t lat1, Longitude_t lon2, Latitude_t lat2);

    // 返回1表示在左右后方，返回0表示不在左右后方
    static bool isLRrear(long lon_hv,long lat_hv,float heading_hv,long lon_rv, long lat_rv);

    // 返回1表示在正前方，返回0表示不在正前方
    static bool isFront(long lon_hv,long lat_hv,float heading_hv,long lon_rv, long lat_rv);

    // 根据TTC来判断FCW是否触发以及预警等级
    static int fcw_level(long lon_hv,long lat_hv,long heading_hv,long speed_hv,long lon_rv,long lat_rv,float heading_rv,long speed_rv);

};

}



#endif //V2XALGORITHM_H
