//
// Created by xuqi on 2019-07-20.
//

#ifndef V2XFACILITYMGNT_H
#define V2XFACILITYMGNT_H

#include "V2xCANProducer.h"
#include "V2xGNSSProducer.h"
#include "V2xITSProducer.h"

namespace  v2x {

class V2xFacilityMgnt
{
public:

    friend  class V2xFacilityAPI;
    typedef shared_ptr<V2xFacilityMgnt> Ptr;
    typedef RecycleResourcePool<V2xMsg>::ValuePtr ValuePtr;
    typedef MsgQueue<ValuePtr> Queue;

    void run();
    V2xFacilityMgnt();

private:
    Queue::Ptr _data_pool;

    V2xITSProducer::Ptr _rv_producer;
    V2xGNSSProducer::Ptr _hv_producer;
};

}


#endif //V2XFACILITYMGNT_H
