//
// Created by root on 19-8-7.
//

#include <V2xMsg.h>
#include "V2xHvMapSpatCal.h"
#include "V2xMsg.h"

namespace v2x
{
void V2xHvMapSpatCal::run()
{
    V2xMsg::ValuePtr msg;
    while (this->_broker->_hv_data_queue->pop(msg)) {
        if (msg->u.hvbsm.speed > 0)
        {
            InfoL << "自车开始动了 speed" <<msg->u.hvbsm.speed;
        }
        TraceL << "HV: Lat=" << msg->u.hvbsm.pos.lat << "  Lon=" << msg->u.hvbsm.pos.lon;
    }
}

V2xHvMapSpatCal::V2xHvMapSpatCal(const shared_ptr<V2xBroker> &broker)
{
    this->_broker = broker;
}

}