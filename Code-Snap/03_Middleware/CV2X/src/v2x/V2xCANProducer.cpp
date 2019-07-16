//
// Created by xuqi on 2019-07-16.
//

#include <v2x/V2xMsg.h>
#include "V2xCANProducer.h"

#include "test/TestCANProducer.h"

using namespace test;

V2xCANProducer::V2xCANProducer(Queue::Ptr &queue)
    : Producer()
{
    _hv_can_pool.setSize(100);
    _hv_can_queue = queue;
}

V2xCANProducer::~V2xCANProducer()
{

}

void V2xCANProducer::run()
{

    while (1) {

        ValuePtr hvcan= _hv_can_pool.obtain();

        hvcan->setMsgType(V2xMsg::MSG_TYPE_CAN);
        TestCANProducer::Inst().update();

        hvcan->u.hvcan.setSpeed(TestCANProducer::Inst().getSpeed());
        hvcan->u.hvcan.setEngineStatus(TestCANProducer::Inst().getEngineStatus());
        hvcan->u.hvcan.setSteerWhlAngle(TestCANProducer::Inst().getSteerWhlAngle());
        hvcan->Print();

        _hv_can_queue->push(hvcan);

        usleep(1000 * 1000);

    }
}