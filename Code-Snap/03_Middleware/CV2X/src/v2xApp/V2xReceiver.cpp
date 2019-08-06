//
// Created by xuqi on 2019-07-22.
//

#include "v2xApp/V2xReceiver.h"
#include "v2xStack/V2xFacifAPI.h"
#include "v2xApp/V2xSetting.h"

#include <exception>

namespace v2x
{
void V2xReceiver::run()
{
    V2xFacifAPI::Instance().init();

    if (SET["Debug.ScenceReplayFlag"].as<bool>())
    {

    }
    else
    {

    }

    distribute();
}
void V2xReceiver::distribute()
{
    V2xFacifAPI::ValuePtr msg;
    while (V2xFacifAPI::Instance().recv(msg)) {

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
