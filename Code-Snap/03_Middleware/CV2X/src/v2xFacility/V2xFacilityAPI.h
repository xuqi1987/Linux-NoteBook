//
// Created by xuqi on 2019-07-20.
//

#ifndef V2XFACILITYAPI_H
#define V2XFACILITYAPI_H

#include "V2xMsg.h"
#include "Util/RecycleResourcePool.h"
#include "MsgQueue.h"
#include "V2xFacilityMgnt.h"


using namespace toolkit;
using namespace mwkit;

class V2xFacilityMgnt;

namespace v2x {

class V2xFacilityAPI
{
public:
    static V2xFacilityAPI & Instance();

    typedef shared_ptr<V2xFacilityAPI> Ptr;
    typedef RecycleResourcePool<V2xMsg>::ValuePtr ValuePtr;
    typedef MsgQueue<ValuePtr> Queue;

    void init();
    bool recv(ValuePtr &msg);
private:
    V2xFacilityMgnt::Ptr _facilityImp;
};



}


#endif //V2XFACILITYAPI_H
