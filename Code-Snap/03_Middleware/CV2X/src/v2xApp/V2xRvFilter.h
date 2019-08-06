//
// Created by root on 19-7-23.
//

#ifndef CV2X_V2XRVFILTER_H
#define CV2X_V2XRVFILTER_H
#include <iostream>
#include <memory>
#include <thread>
#include <future>
#include "Util/RecycleResourcePool.h"
#include "v2xUtil/V2xMsg.h"

using namespace std;

namespace v2x {
class V2xRvFilter
{
public:
    typedef shared_ptr<V2xRvFilter> Ptr;
    bool isDiscard(V2xMsg::ValuePtr &pHv, V2xMsg::ValuePtr &pRv);

};
}



#endif //CV2X_V2XRVFILTER_H
