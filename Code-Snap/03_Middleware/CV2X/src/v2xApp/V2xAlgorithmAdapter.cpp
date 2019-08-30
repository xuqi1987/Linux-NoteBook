//
// Created by root on 19-8-23.
//

#include <V2xAlgorithmAdapter.h>

#include "V2xAlgorithmAdapter.h"

namespace v2x {



double V2xAlgorithmAdapter::GetDistance(V2xBSMMsg &hv, V2xBSMMsg &rv)
{
    double lon_hv = Pos2Double(hv.pos.lon); //deg
    double lat_hv = Pos2Double(hv.pos.lat); //deg

    double lon_rv = Pos2Double(rv.pos.lon);
    double lat_rv = Pos2Double(rv.pos.lat);

    return V2xAlgorithmTest::GetDistance(lon_hv, lat_hv, lon_rv, lat_rv);
}

V2xAlgorithmTest::Direction V2xAlgorithmAdapter::GetRVDirection(V2xBSMMsg &hv, V2xBSMMsg &rv)
{
    double heading_hv = Heading2Double(hv.heading);
    double heading_rv = Heading2Double(rv.heading);

    return V2xAlgorithmTest::RelHeadingJudge(heading_hv,heading_rv);
}
}