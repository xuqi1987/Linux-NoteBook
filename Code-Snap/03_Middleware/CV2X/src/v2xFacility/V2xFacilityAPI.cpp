//
// Created by xuqi on 2019-07-20.
//

#include "V2xFacilityAPI.h"
#include "Util/Util.h"

namespace v2x
{

INSTANCE_IMP(V2xFacilityAPI)
void v2x::V2xFacilityAPI::init()
{
    _facilityImp = make_shared<V2xFacilityMgnt>();
    _facilityImp->run();
}

bool v2x::V2xFacilityAPI::recv(ValuePtr &msg)
{
    return _facilityImp->_data_pool->pop(msg);
}

}
