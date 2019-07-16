//
// Created by xuqi on 2019-07-16.
//

#include "TestITSProducer.h"
void test::TestITSProducer::update()
{
    uniform_int_distribution<uint32_t> id(1, 9);
    _id = id(e);

    _sec_mark = 0;

    uniform_int_distribution<uint32_t> latitude(1, 9);
    _latitude = latitude(e);

    uniform_int_distribution<uint32_t> longitude(1, 9);
    _longitude = longitude(e);

    uniform_int_distribution<uint32_t> speed(1, 9);
    _speed = speed(e);

    uniform_int_distribution<uint32_t> heading(1, 9);
    _heading = heading(e);


}
