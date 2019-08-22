//
// Created by xuqi on 2019-07-22.
//

#include "V2xBroker.h"
#include "V2xHvMapSpatCal.h"
#include "V2xRvThreadPool.h"
namespace v2x {

void V2xBroker::Run()
{
    m_pRvThreads  = make_shared<V2xRvThreadPool>(this->shared_from_this(),10);
    m_pHvMapSpat = make_shared<V2xHvMapSpatCal>(this->shared_from_this());
    m_pBsmQueue =  make_shared<V2xMsg::Queue>();

    if (nullptr == m_pRvThreads
    || nullptr == m_pHvMapSpat)
    {
        ErrorL << "Null point Error";
        return;
    }

    m_pRvThreads->Start();
    m_pHvMapSpat->run();
}

V2xBroker::V2xBroker()
{
    m_scenePool.setSize(100);
}

void V2xBroker::setHvDataQueue(V2xMsg::Queue::Ptr &pHvDataQueue)
{
    m_pHvDataQueue = pHvDataQueue;
}

void V2xBroker::setRvDataQueue(V2xMsg::Queue::Ptr &pRvDataQueue)
{
    m_pRvDataQueue = pRvDataQueue;
}

void V2xBroker::setSceneOutQueue(V2xSceneMsg::Queue::Ptr &pSceneOutQueue)
{
    m_pSceneOutQueue = pSceneOutQueue;
}


}

