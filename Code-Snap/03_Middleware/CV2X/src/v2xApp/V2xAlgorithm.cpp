//
// Created by xuqi on 2019-07-17.
//

#include <cmath>
#include "V2xAlgorithm.h"

namespace v2x
{

double V2xAlgorithm::Lonlat2dis(Longitude_t lon1, Latitude_t lat1, Longitude_t lon2, Latitude_t lat2)
{
    return V2xAlgorithm::Lonlat2dis(lon1/1000000.0,lat1/1000000.0,lon2/1000000.0,lat2/1000000.0);
}

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

}
