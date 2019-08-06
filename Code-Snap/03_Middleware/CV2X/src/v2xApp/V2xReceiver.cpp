//
// Created by xuqi on 2019-07-22.
//

#include "v2xApp/V2xReceiver.h"
#include "v2xApp/V2xSetting.h"

#include <exception>
#include <v2xUtil/V2xMsg.h>


namespace  v2x {

void V2xReceiver::distribute(V2xMsg::ValuePtr &&msg)
{
    msg->Print();
    switch (msg->getMsgType()) {
        case V2xMsg::MSG_TYPE_HV_BSM:
            TraceL << "V2xReceiver HV 分配:" << msg;
            _hv_data_queue->push(msg);
            _curCar = msg;
            break;
        case V2xMsg::MSG_TYPE_RV_BSM: {
            if (!_filter->isDiscard(msg, _curCar)) {

                TraceL << "V2xReceiver RV 分配:" << msg;
                _rv_data_queue->push(msg);
            }
        }
            break;
        default:break;
    }

}
void V2xReceiver::setHvDataQueue(V2xMsg::Queue::Ptr &q)
{
    _hv_data_queue = q;
}

void V2xReceiver::setRvDataQueue(V2xMsg::Queue::Ptr &q)
{
    _rv_data_queue = q;
}

V2xReceiver::V2xReceiver()
    : _hv_data_queue(nullptr), _rv_data_queue(nullptr), _filter(nullptr)
{
    _filter = make_shared<V2xRvFilter>();
    _recv_proxy = make_shared<V2xReceiverProxy>();
    _recycleResourcePool.setSize(100);
}

void V2xReceiver::run()
{
    InfoL << "V2xReceiver Thread Start" << endl;
    if (_recv_proxy == nullptr) {
        ErrorL << "recv_proxy is null";
    }
    _recv_proxy->init();

    V2xMsg::ValuePtr msg = _recycleResourcePool.obtain();

    while (_recv_proxy->recv(move(msg))) {

        distribute(std::move(msg));
        // 获取一个msg
        msg = _recycleResourcePool.obtain();
    }

}

}
