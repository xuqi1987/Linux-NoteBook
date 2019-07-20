//
// Created by xuqi on 2019-07-16.
//

#ifndef TESTGNSSPRODUCER_H
#define TESTGNSSPRODUCER_H

#include <string>
#include <random>
#include "v2xFacility/V2xMsg.h"

using namespace std;
using namespace v2x;

namespace test
{

class TestGNSSProducer : public V2xGNSSMsg
{
public:

    static TestGNSSProducer &Inst()
    {
        static TestGNSSProducer sInst;
        return sInst;
    }


    void update();
private:
    default_random_engine e;

};
}


#endif //TESTGNSSPRODUCER_H
