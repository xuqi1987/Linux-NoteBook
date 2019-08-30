//
// Created by root on 19-8-22.

#include "V2xAlgorithmAdapter.h"
#include <cmath>

#include <iostream>
using namespace v2x;
int main()
{

    double lon_hv = 116.427800;
    double lat_hv = 39.912462;
    double lon_rv = 116.427801;
    double lat_rv = 39.912462;
    double speed_hv  = 30.0;
    double speed_rv  = 66.0;

    double heading_hv = 0;
    double heading_rv = 0;

    std::cout << "距离"<< V2xAlgorithmTest::GetDistance(lon_hv, lat_hv, lon_rv, lat_rv)<< "m" << std::endl;


    V2xAlgorithmTest::RelPosPoints_t pos;
    V2xAlgorithmTest::GetXYDistance(lon_hv, lat_hv, lon_rv, lat_rv, 0, pos);

    std::cout << "X:" << pos.x << "Y:" << pos.y << std::endl;

    std::cout << "Distance:" << sqrt(pos.x*pos.x + pos.y *pos.y);
    std::cout << V2xAlgorithmTest::RvRelPosition(pos,2,2);

    return 0;
}