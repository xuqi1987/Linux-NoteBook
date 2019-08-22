//
// Created by root on 19-7-11.
//

#include "V2xApp.h"
#include "Util/Logger.h"
#include "V2xException.h"
namespace v2x
{

V2xApp::V2xApp()
{
    // 接收消息
    m_pReceiver = make_shared<V2xReceiver>();
    m_pHvOutQueue = make_shared<V2xMsg::Queue>();
    m_pRvOutQueue = make_shared<V2xMsg::Queue>();

    m_pSceneOutQueue = make_shared<V2xSceneMsg::Queue>();

    m_pBroker = make_shared<V2xBroker>();
    m_pSender = make_shared<V2xSender>();

}

V2xApp::~V2xApp()
{

}
void V2xApp::Run()
{

    if (nullptr == m_pSender
    || nullptr == m_pBroker
    || nullptr == m_pReceiver)
    {
        ErrorL << "Null point Error";
        return;
    }
    /*
    m_pSender->SetSceneQueue(m_pSceneOutQueue);
    m_pSender->Start();
    usleep(1000);
*/

    m_pBroker->setHvDataQueue(m_pHvOutQueue);
    m_pBroker->setRvDataQueue(m_pRvOutQueue);
    m_pBroker->setSceneOutQueue(m_pSceneOutQueue);
    m_pBroker->Start();
    usleep(1000);

    m_pReceiver->SetHvDataQueue(m_pHvOutQueue);
    m_pReceiver->SetRvDataQueue(m_pRvOutQueue);
    m_pReceiver->Start();



}

}
