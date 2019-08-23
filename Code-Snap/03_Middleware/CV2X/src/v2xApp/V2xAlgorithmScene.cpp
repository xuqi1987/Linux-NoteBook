//
// Created by root on 19-8-23.
//

#include "V2xAlgorithmScene.h"

namespace v2x {

bool v2x::V2xAlgorithmScene::IsFWCWarning(double lon_hv,
                                          double lat_hv,
                                          double heading_hv,
                                          double speed_hv,
                                          double lon_rv,
                                          double lat_rv,
                                          double heading_rv,
                                          double speed_rv)
{
    // 先判断在正前方
     if (abs(int(heading_hv) - int(heading_rv)) < 3)
    //if (V2xAlgorithmTest::IsFront(lon_hv,lat_hv,heading_hv,lon_rv,lat_rv))
    {
        // 低速跟驰碰撞
        if ((speed_hv < 15.0) && (speed_hv > 2.0))
        {
            if (V2xAlgorithmTest::Lonlat2dis(lon_hv,lat_hv,lon_rv,lat_rv) < 50 ) // < 50cm
            {
                return true;
            }
        }
        // 追尾碰撞
        if (speed_hv > 15.0)
        {

            // 预计 3S 后将发生碰撞时给用户预警
            if (V2xAlgorithmTest::CalVecicleTTC(lon_hv,lat_hv,heading_hv,speed_hv,lon_rv,lat_rv,heading_rv,speed_rv) < 3.0)
            {
                return true;
            }
        }

        // 高速跟驰碰撞
        if (speed_hv > 60.0)
        {
            if (V2xAlgorithmTest::Lonlat2dis(lon_hv,lat_hv,lon_rv,lat_rv) < 3000 ) // < 3000cm
            {
                return true;
            }
        }

        std::cout << "速度不符合" << std::endl;

    }

    return false;
}

}
