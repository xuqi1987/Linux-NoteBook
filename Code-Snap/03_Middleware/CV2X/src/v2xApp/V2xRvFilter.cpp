//
// Created by root on 19-7-23.
//

#include <V2xMsg.h>
#include "V2xRvFilter.h"
#include "V2xAlgorithm.h"

namespace v2x {

bool V2xRvFilter::isDiscard(V2xMsg::ValuePtr &pHv, V2xMsg::ValuePtr &pRv)
{
    long dis =V2xAlgorithm::lonlat2dis(pHv->u.hvbsm.pos.lon,pHv->u.hvbsm.pos.lat,pRv->u.rvbsm.pos.lon,pRv->u.rvbsm.pos.lat);
    InfoL << "HV:"<<pHv->u.hvbsm.id <<" RV:"<< pRv->u.rvbsm.id <<" 两车距离: " << dis << "cm";
    return false;
}

}

