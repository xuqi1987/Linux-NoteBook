//
// Created by root on 19-8-22.
//
#include "V2xAlgorithm.h"
#include <iostream>
using namespace v2x;
int main()
{

    double dlon1 = 116.427800;
    double dlat1 = 39.912462;
    double dlon2 = 116.428038;
    double dlat2 = 39.912458;
    // 9299.65m

    std::cout << V2xAlgorithm::Lonlat2dis(dlon1,dlat1,dlon2,dlat2) << "cm";
    return 0;
}