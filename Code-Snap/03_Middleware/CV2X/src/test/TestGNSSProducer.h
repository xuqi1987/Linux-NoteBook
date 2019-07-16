//
// Created by xuqi on 2019-07-16.
//

#ifndef TESTGNSSPRODUCER_H
#define TESTGNSSPRODUCER_H

#include <string>
#include <random>

using namespace std;
namespace test
{

class TestGNSSProducer
{
public:

    static TestGNSSProducer &Inst()
    {
        static TestGNSSProducer sInst;
        return sInst;
    }

private:
    uint32_t _latitude;
public:
    uint32_t getLatitude() const
    {
        return _latitude;
    }
    uint32_t getLongitude() const
    {
        return _longitude;
    }
    uint32_t getAltitude() const
    {
        return _altitude;
    }
    uint32_t getSpeed() const
    {
        return _speed;
    }
    uint32_t getHeading() const
    {
        return _heading;
    }

    void update();
private:
    default_random_engine e;
    uint32_t _longitude;
    uint32_t _altitude;
    uint32_t _speed;
    uint32_t _heading;
};
}


#endif //TESTGNSSPRODUCER_H
