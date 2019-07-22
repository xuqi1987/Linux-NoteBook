//
// Created by xuqi on 2019-07-20.
//

#include "V2xFacilityMgnt.h"
namespace v2x {

void V2xFacilityMgnt::run()
{
    _data_pool = make_shared<V2xFacilityMgnt::Queue>();

    _rv_producer = make_shared<V2xITSProducer>(_data_pool);
    _hv_producer = make_shared<V2xGNSSProducer>(_data_pool);

    _hv_producer->start();
    usleep(1000 * 10);
    _rv_producer->start();

   // DebugL << "V2xFacilityMgnt::run()";
}

V2xFacilityMgnt::V2xFacilityMgnt()
{

}
}

