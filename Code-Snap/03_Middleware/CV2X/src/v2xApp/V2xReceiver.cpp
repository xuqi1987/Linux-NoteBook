//
// Created by xuqi on 2019-07-22.
//

#include "v2xApp/V2xReceiver.h"
#include <exception>
void v2x::V2xReceiver::run()
{
    v2xStackAPI::Instance().init();
    distribute();
}
void v2x::V2xReceiver::distribute()
{

    v2xStackAPI::ValuePtr msg;
    while (v2xStackAPI::Instance().recv(msg))
    {
        switch (msg->getMsgType())
        {
            case V2xMsg::MSG_TYPE_HV_BSM:
                _hv_data_queue->push(msg);
                _curCar = msg;

                break;
            case V2xMsg::MSG_TYPE_RV_BSM:
                _rv_data_queue->push(msg);
                _filter->

                break;
            default:
                break;
        }
    }

}
void V2xReceiver::setHvDataQueue(Queue::Ptr &q)
{
    _hv_data_queue = q;


}
void V2xReceiver::setRvDataQueue(Queue::Ptr &q)
{
    _rv_data_queue = q;

}
V2xReceiver::V2xReceiver()
    : _hv_data_queue(nullptr), _rv_data_queue(nullptr), _filter(nullptr)
{
    _filter = make_shared<V2xRvFilter>();
}

