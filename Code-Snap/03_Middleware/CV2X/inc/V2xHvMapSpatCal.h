//
// Created by root on 19-8-7.
//

#ifndef CV2X_V2XHVMAPSPATCAL_H
#define CV2X_V2XHVMAPSPATCAL_H
#include "V2xThread.h"
#include "Thread/ThreadPool.h"

#include "V2xBroker.h"


namespace v2x
{

class V2xHvMapSpatCal
{
public:
    typedef shared_ptr<V2xHvMapSpatCal> Ptr;
    V2xHvMapSpatCal(const shared_ptr<V2xBroker> &broker);
    void run();
private:
    V2xBroker::Ptr _broker;

};

}


#endif //CV2X_V2XHVMAPSPATCAL_H
