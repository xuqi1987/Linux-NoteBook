//
// Created by xuqi on 2019-07-20.
//

#ifndef V2XSTACKAPI_H
#define V2XSTACKAPI_H

#include "v2xApp/V2xMsg.h"
#include "Util/RecycleResourcePool.h"
#include "v2xUtil/V2xMsgQueue.h"
#include "V2xFacilityMgnt.h"


using namespace toolkit;

class V2xFacilityMgnt;

namespace v2x {

class v2xStackAPI
{
public:
    static v2xStackAPI & Instance();

    typedef shared_ptr<v2xStackAPI> Ptr;
    typedef RecycleResourcePool<V2xMsg>::ValuePtr ValuePtr;
    typedef V2xMsgQueue<ValuePtr> Queue;

    void init();
    bool recv(ValuePtr &msg);
private:
    V2xFacilityMgnt::Ptr _facilityImp;
};



}


#endif //V2XSTACKAPI_H
