//
// Created by root on 19-7-11.
//

#include "V2xApp.h"
#include "v2xStack/v2xStackAPI.h"
#include "Util/Logger.h"
namespace v2x
{

V2xApp::V2xApp()
{
    // 接收消息
    _receiver = make_shared<V2xReceiver>();
    _hv_out_queue = make_shared<V2xMsg::Queue>();
    _rv_out_queue = make_shared<V2xMsg::Queue>();

    _scene_out_queue = make_shared<V2xScene::Queue>();

    _broker = make_shared<V2xBroker>();
    _sender = make_shared<V2xSender>();


}

void V2xApp::run()
{

    try {

        // 设置Receiver的输出是_hv_out_pool和_rv_out_pool
        _receiver->setHvDataQueue(_hv_out_queue);
        _receiver->setRvDataQueue(_rv_out_queue);
        _receiver->start();


        _broker->setHvDataQueue(_hv_out_queue);
        _broker->setRvDataQueue(_rv_out_queue);
        _broker->setSceneOutQueue(_scene_out_queue);
        _broker->start();

        _sender->start();
    }
    catch (...)
    {
        ErrorL << "Error";
    }


}

}
