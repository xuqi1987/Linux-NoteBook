//
// Created by xuqi on 2019-07-16.
//

#include "TestGNSSProducer.h"
void test::TestGNSSProducer::update()
{


    uniform_int_distribution<uint32_t> latitude(1, 9);
    this->setLatitude(latitude(e));

    uniform_int_distribution<uint32_t> longitude(1, 9);
    this->setLongitude(longitude(e));

    uniform_int_distribution<uint32_t> speed(100, 200);
    this->setSpeed(speed(e));

    uniform_int_distribution<uint32_t> heading(1, 9);
    this->setHeading(heading(e));
}
