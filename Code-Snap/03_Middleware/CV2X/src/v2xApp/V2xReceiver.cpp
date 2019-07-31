//
// Created by xuqi on 2019-07-22.
//

#include "v2xApp/V2xReceiver.h"
#include <exception>

namespace v2x
{


void V2xReceiver::run()
{
    // 测试程序启动，模拟发假数据
    v2xStackAPI::Instance().init();


    distribute();
}
void V2xReceiver::distribute()
{

    v2xStackAPI::ValuePtr msg;
    while (v2xStackAPI::Instance().recv(msg)) {

        switch (msg->getMsgType()) {
            case V2xMsg::MSG_TYPE_HV_BSM:TraceL << "V2xReceiver HV 分配:" << msg;
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
}

}
