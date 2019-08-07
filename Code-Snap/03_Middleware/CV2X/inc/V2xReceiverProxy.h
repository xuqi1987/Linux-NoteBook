//
// Created by xuqi on 2019-08-06.
//

#ifndef V2XRECEIVERPROXY_H
#define V2XRECEIVERPROXY_H
#include <memory>
#include <thread>
#include <future>
#include "csv/csv.h"
#include <string>
#include "V2xSetting.h"

using namespace std;
using namespace io;

namespace v2x {

class IV2xReceiver {
public:
    typedef shared_ptr<IV2xReceiver> Ptr;
    virtual void init() = 0;
    virtual bool recv(V2xMsg::ValuePtr && msg) = 0;
};

class V2xSavariReceiver : public IV2xReceiver {
public:
    void init() override;
    bool recv(V2xMsg::ValuePtr &&msg) override;
};

class V2xReplayReceiver : public IV2xReceiver {
public:
    void init() override;
    bool recv(V2xMsg::ValuePtr &&msg) override;
private:
    shared_ptr<CSVReader<7>> _csv;
};

class V2xReceiverProxy : public IV2xReceiver
{
public:
    typedef shared_ptr<V2xReceiverProxy> Ptr;
    void init() override;
    bool recv(V2xMsg::ValuePtr &&msg) override;

private:
    IV2xReceiver::Ptr _receiver;

};

}

#endif //V2XRECEIVERPROXY_H
