//
// Created by xuqi on 2019-07-16.
//

#ifndef CV2X_SRC_TEST_TESTITSPRODUCER_H_
#define CV2X_SRC_TEST_TESTITSPRODUCER_H_

#include <string>
#include <random>

using namespace std;
namespace test
{

class TestITSProducer
{
public:

    static TestITSProducer &Inst()
    {
        static TestITSProducer sInst;
        return sInst;
    }

    uint32_t getSecMark() const
    {
        return _sec_mark;
    }
    uint32_t getLatitude() const
    {
        return _latitude;
    }
    uint32_t getLongitude() const
    {
        return _longitude;
    }
    uint32_t getSpeed() const
    {
        return _speed;
    }
    uint32_t getHeading() const
    {
        return _heading;
    }
    uint32_t getId() const
    {
        return _id;
    }

    void update();

private:
    default_random_engine e;

    uint32_t _id;

    uint32_t _sec_mark;
    uint32_t _latitude;

    uint32_t _longitude;
    uint32_t _speed;
    uint32_t _heading;

};
}


#endif //CV2X_SRC_TEST_TESTITSPRODUCER_H_
