//
// Created by xuqi on 2019-07-17.
//

#include "V2xAlgorithm.h"

namespace v2x
{
/**
 *
 * @param lon1 百万分之一度
 * @param lat1
 * @param lon2
 * @param lat2
 * @return cm
 */
long V2xAlgorithm::lonlat2dis(Longitude_t lon1, Latitude_t lat1, Longitude_t lon2, Latitude_t lat2)
{
    return V2xAlgorithm::lonlat2dis(lon1/1000000.0,lat1/1000000.0,lon2/1000000.0,lat2/1000000.0);
}

double V2xAlgorithm::rad(double d)
{
    return d * PI / 180.0;
}

long V2xAlgorithm::lonlat2dis(double lon1, double lat1, double lon2, double lat2)
{

    DebugL << setprecision(9) <<lon1 << " "<< lat1 << " | " << lon2 << " "  <<lat2;
    double radLat1 = rad(lat1);
    double radLat2 = rad(lat2);
    double a = radLat1 - radLat2;
    double b = rad(lon1) - rad(lon2);

    double s = 2 * asin(sqrt(pow(sin(a / 2), 2) + cos(radLat1) * cos(radLat2) * pow(sin(b / 2), 2)));
    s = s * EARTH_RADIUS;

    s = round(s * 10000) * 10;


    return s;
}
}

