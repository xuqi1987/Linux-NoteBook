//
// Created by xuqi on 2019-07-16.
//

#ifndef TESTCANPRODUCER_H
#define TESTCANPRODUCER_H

#include <string>
#include <random>
#include "v2x/V2xMsg.h"

using namespace std;
using namespace v2x;


namespace test
{

class TestCANProducer : public V2xCANMsg
{
public:

    static TestCANProducer &Inst()
    {
        static TestCANProducer sInst;
        return sInst;
    }


    void update();
private:
    default_random_engine e;

};

}

#endif //TESTCANPRODUCER_H
