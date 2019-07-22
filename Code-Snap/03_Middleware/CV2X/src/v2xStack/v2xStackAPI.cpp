//
// Created by xuqi on 2019-07-20.
//

#include "v2xStackAPI.h"
#include "Util/Util.h"

namespace v2x
{

INSTANCE_IMP(v2xStackAPI)
void v2x::v2xStackAPI::init()
{
    _facilityImp = make_shared<V2xFacilityMgnt>();
    _facilityImp->run();
}

bool v2x::v2xStackAPI::recv(ValuePtr &msg)
{
    return _facilityImp->_data_pool->pop(msg);
}

}
