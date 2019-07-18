//
// Created by xuqi on 2019-07-16.
//

#include "TestCANProducer.h"
void test::TestCANProducer::update()
{
    uniform_int_distribution<uint32_t> speed(1, 9);
    this->setSpeed(speed(e));

    uniform_int_distribution<uint32_t> steer_whl_angle(1, 9);
    this->setSteerWhlAngle(steer_whl_angle(e));

    uniform_int_distribution<uint32_t> engine_status(1, 9);
    this->setEngineStatus(engine_status(e));
}
