//
// Created by root on 19-8-22.
//
#include "V2xAlgorithmTest.h"
#include "V2xAlgorithmAdapter.h"

#include <iostream>
using namespace v2x;
int main()
{

    double lon_hv = 116.427800;
    double lat_hv = 39.912462;
    double lon_rv = 116.427800;
    double lat_rv = 39.912658;
    double speed_hv  = 30.0;
    double speed_rv  = 66.0;

    double heading_hv = 0;
    double heading_rv = 0;

    std::cout << "距离"<< V2xAlgorithmTest::Lonlat2dis(lon_hv,lat_hv,lon_rv,lat_rv) /100.0<< "m" << std::endl;


    V2xAlgorithm::RelPosPoints_t pos;
    V2xAlgorithm::CoordinateChange(lon_hv,lat_hv,lon_rv,lat_rv,0,pos);

    std::cout << "X:" << pos.x << "Y:" << pos.y;

    return 0;
}