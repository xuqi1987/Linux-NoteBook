//
// Created by xuqi on 2019-07-13.
//

#include <v2x/V2xMsg.h>
#include "V2xGNSSProducer.h"
#include "test/TestGNSSProducer.h"
#include "V2xMsg.h"

using namespace test;
namespace v2x
{

V2xGNSSProducer::V2xGNSSProducer(Queue::Ptr &queue)
    : Producer()
{
    _hv_bsm_pool.setSize(100);
    _hv_bsm_queue = queue;
    _can_producer = make_shared<V2xCANProducer>();
}

V2xGNSSProducer::~V2xGNSSProducer()
{

}

void V2xGNSSProducer::run()
{

    _can_producer->start();

    while (1) {
        ValuePtr gnss = _hv_bsm_pool.obtain();

        gnss->assign("");
        gnss->setMsgType(V2xMsg::MSG_TYPE_HV_BSM);

        TestGNSSProducer::Inst().update();
        gnss->u.hvbsm.setTempId(0);

        gnss->u.hvbsm.setSpeed(_can_producer->getCANMsg().getSpeed());
        gnss->u.hvbsm.setHeading(TestGNSSProducer::Inst().getHeading());
        gnss->u.hvbsm.setLongitude(TestGNSSProducer::Inst().getLongitude());
        gnss->u.hvbsm.setLatitude(TestGNSSProducer::Inst().getLatitude());

        gnss->Print();
        _hv_bsm_queue->push(gnss);

        usleep(1000 * 1000);

    }
}
}
