//
// Created by xuqi on 2019-07-22.
//

#ifndef V2XBROKER_H
#define V2XBROKER_H
#include "V2xThread.h"

namespace v2x {

class V2xBroker : public V2xThread
{
public:
    typedef shared_ptr<V2xBroker> Ptr;
    void run() override;
};

}

#endif //V2XBROKER_H
