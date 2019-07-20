//
// Created by root on 19-7-11.
//

#include "V2xApp.h"
#include "v2xFacility/V2xFacilityAPI.h"
#include "Util/Logger.h"
namespace v2x
{

V2xApp::V2xApp()
{

}

void V2xApp::run()
{
    V2xFacilityAPI::Instance().init();
    V2xFacilityAPI::ValuePtr msg;
    _hv_data_queue = make_shared<V2xFacilityAPI::Queue>();
    _rv_data_queue = make_shared<V2xFacilityAPI::Queue>();

    while (V2xFacilityAPI::Instance().recv(msg))
    {
       switch (msg->getMsgType())
       {
           case V2xMsg::MSG_TYPE_HV_BSM:
               _hv_data_queue->push(msg);
               break;
           case V2xMsg::MSG_TYPE_RV_BSM:
               _rv_data_queue->push(msg);
               break;
           default:
               break;
       }
    }

}



}
