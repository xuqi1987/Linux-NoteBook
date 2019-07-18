//
// Created by xuqi on 2019-07-16.
//

#ifndef V2XCANPRODUCER_H
#define V2XCANPRODUCER_H

#include <iostream>
#include <memory>
#include <thread>
#include <future>
#include "Util/Logger.h"
#include "V2xMsg.h"
#include "Producer.h"

using namespace std;
using namespace v2x;
using namespace toolkit;
using namespace mwkit;


class V2xCANProducer: public Producer
{
public:
    typedef shared_ptr<V2xCANProducer> Ptr;

    V2xCANProducer();
    virtual ~V2xCANProducer();
    void run() override;
    const V2xCANMsg &getCANMsg() const;

private:
    V2xCANMsg _can_msg;

};


#endif //V2XCANPRODUCER_H
