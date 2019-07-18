//
// Created by xuqi on 2019-07-16.
//

#ifndef CV2X_SRC_TEST_TESTITSPRODUCER_H_
#define CV2X_SRC_TEST_TESTITSPRODUCER_H_

#include <string>
#include <random>
#include "v2x/V2xMsg.h"

using namespace std;
using namespace v2x;
namespace test
{

class TestITSProducer : public V2xBSMMsg
{
public:

    static TestITSProducer &Inst()
    {
        static TestITSProducer sInst;
        return sInst;
    }


    void update();


private:
    default_random_engine e;



};
}


#endif //CV2X_SRC_TEST_TESTITSPRODUCER_H_
