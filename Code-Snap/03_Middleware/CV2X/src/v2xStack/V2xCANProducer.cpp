//
// Created by xuqi on 2019-07-16.
//

#include "v2xApp/V2xMsg.h"
#include "V2xCANProducer.h"

#include "test/TestCANProducer.h"

using namespace test;

namespace v2x
{


V2xCANProducer::~V2xCANProducer()
{

}

void V2xCANProducer::run()
{

    while (1) {

        TestCANProducer::Inst().update();

        _can_msg.setSpeed(TestCANProducer::Inst().getSpeed());
        _can_msg.setEngineStatus(TestCANProducer::Inst().getEngineStatus());
        _can_msg.setSteerWhlAngle(TestCANProducer::Inst().getSteerWhlAngle());

        usleep(1000 * 100);

    }
}
V2xCANProducer::V2xCANProducer()
{

}
const V2xCANMsg &V2xCANProducer::getCANMsg() const
{
    return _can_msg;
}
}