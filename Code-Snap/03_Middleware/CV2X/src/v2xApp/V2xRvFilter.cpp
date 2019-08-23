//
// Created by root on 19-7-23.
//

#include <V2xMsg.h>
#include "V2xRvFilter.h"
#include "V2xAlgorithmTest.h"
#include "V2xAlgorithmAdapter.h"

namespace v2x {

bool V2xRvFilter::isDiscard(V2xMsg::ValuePtr &pHv, V2xMsg::ValuePtr &pRv)
{
    //long dis =V2xAlgorithmAdapter::Lonlat2dis(pHv->u.hvbsm.pos.lon,pHv->u.hvbsm.pos.lat,pRv->u.rvbsm.pos.lon,pRv->u.rvbsm.pos.lat);
    //InfoL << "HV:"<<pHv->u.hvbsm.id <<" RV:"<< pRv->u.rvbsm.id <<" 两车距离: " << dis << "cm";
    static double lastdis = 0.0;

    double newdis = V2xAlgorithmAdapter::Lonlat2dis(pHv,pRv);

    if (newdis != lastdis)
    {
        DebugL <<" 两车距离: " << newdis/100.0 << "m";
        lastdis = newdis;
    }

    return false;
}

}

