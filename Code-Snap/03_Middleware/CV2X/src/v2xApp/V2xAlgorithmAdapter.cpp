//
// Created by root on 19-8-23.
//

#include <V2xAlgorithmAdapter.h>

#include "V2xAlgorithmAdapter.h"

namespace v2x {




bool V2xAlgorithmAdapter::IsFWCWarning(V2xMsg::Ptr &hv, V2xMsg::Ptr &rv)
{
    double lon_hv = Pos2Double(hv->u.hvbsm.pos.lon); //deg
    double lat_hv = Pos2Double(hv->u.hvbsm.pos.lat); //deg
    double heading_hv = Heading2Double(hv->u.hvbsm.heading); // deg
    double speed_hv = Speed2Double(hv->u.hvbsm.speed); // km
    double lon_rv = Pos2Double(rv->u.rvbsm.pos.lon);
    double lat_rv = Pos2Double(rv->u.rvbsm.pos.lat);
    double heading_rv = Heading2Double(rv->u.hvbsm.heading);
    double speed_rv =Speed2Double(rv->u.rvbsm.speed);

    return V2xAlgorithmScene::IsFWCWarning(lon_hv,lat_hv,heading_hv,speed_hv,lon_rv,lat_rv,heading_rv,speed_rv);

}
double V2xAlgorithmAdapter::Lonlat2dis(V2xMsg::Ptr &hv, V2xMsg::Ptr &rv)
{
    double lon_hv = Pos2Double(hv->u.hvbsm.pos.lon); //deg
    double lat_hv = Pos2Double(hv->u.hvbsm.pos.lat); //deg

    double lon_rv = Pos2Double(rv->u.rvbsm.pos.lon);
    double lat_rv = Pos2Double(rv->u.rvbsm.pos.lat);

    return V2xAlgorithmTest::Lonlat2dis(lon_hv,lat_hv,lon_rv,lat_rv);
}
}