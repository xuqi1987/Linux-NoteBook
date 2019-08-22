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
    virtual void Init() = 0;
    virtual bool Recv(V2xMsg::ValuePtr &&pMsg) = 0;
};

class V2xSavariReceiver : public IV2xReceiver {
public:
    void Init() override;
    bool Recv(V2xMsg::ValuePtr &&pMsg) override;
};

class V2xReplayReceiver : public IV2xReceiver {
public:
    void Init() override;
    bool Recv(V2xMsg::ValuePtr &&pMsg) override;
private:
    shared_ptr<CSVReader<7>> _csv;
};

class V2xReceiverProxy : public IV2xReceiver
{
public:
    typedef shared_ptr<V2xReceiverProxy> Ptr;
    void Init() override;
    bool Recv(V2xMsg::ValuePtr &&pMsg) override;

private:
    IV2xReceiver::Ptr m_pReceiver;

};

}

#endif //V2XRECEIVERPROXY_H
