//
// Created by xuqi on 2019-07-16.
//

#ifndef TESTCANPRODUCER_H
#define TESTCANPRODUCER_H

#include <string>
#include <random>

using namespace std;

namespace test
{

class TestCANProducer
{
public:

    static TestCANProducer &Inst()
    {
        static TestCANProducer sInst;
        return sInst;
    }
    uint32_t getSpeed() const
    {
        return _speed;
    }
    uint32_t getSteerWhlAngle() const
    {
        return _steer_whl_angle;
    }
    uint32_t getEngineStatus() const
    {
        return _engine_status;
    }

    void update();
private:
    default_random_engine e;

    uint32_t _speed;
    uint32_t _steer_whl_angle;
    uint32_t _engine_status;
};

}

#endif //TESTCANPRODUCER_H
