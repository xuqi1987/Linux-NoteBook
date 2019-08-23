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

    // 是否是正前方
    std::cout <<"是否正前方" <<V2xAlgorithmTest::IsFront(lon_hv,lat_hv,0,lon_rv,lat_rv) <<std::endl;

    bool isFCW = V2xAlgorithmScene::IsFWCWarning(lon_hv,lat_hv,heading_hv,speed_hv,lon_rv,lat_rv,heading_rv,speed_rv);
    std::cout <<"是否会发生碰撞"<< isFCW<<std::endl;

    return 0;
}