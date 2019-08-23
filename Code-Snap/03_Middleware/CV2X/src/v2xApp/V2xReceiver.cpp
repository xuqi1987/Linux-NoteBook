//
// Created by xuqi on 2019-07-22.
//

#include "V2xReceiver.h"
#include "V2xSetting.h"

#include <exception>
#include <V2xMsg.h>

using namespace std;

namespace v2x
{

void V2xReceiver::distribute(V2xMsg::ValuePtr &&pMsg)
{
    //pMsg->Print();
    switch (pMsg->GetMsgType()) {
        case V2xMsg::MSG_TYPE_HV_BSM:
            TraceL << "V2xReceiver HV 分配:" << m_pHvDataQueue;
            m_pHvDataQueue->push(pMsg);
            m_pCurCar = pMsg;
            break;
        case V2xMsg::MSG_TYPE_RV_BSM: {

            if (m_pCurCar != nullptr) {
                if (!m_pFilter->isDiscard(m_pCurCar, pMsg)) {

                    TraceL << "V2xReceiver RV 分配:" << pMsg;
                    m_pRvDataQueue->push(move(pMsg));
                }
            }

        }
            break;
        default:break;
    }

}
void V2xReceiver::SetHvDataQueue(V2xMsg::Queue::Ptr &pQueue)
{
    m_pHvDataQueue = pQueue;
}

void V2xReceiver::SetRvDataQueue(V2xMsg::Queue::Ptr &pQueue)
{
    m_pRvDataQueue = pQueue;
}

V2xReceiver::V2xReceiver()
    : m_pHvDataQueue(nullptr), m_pRvDataQueue(nullptr), m_pFilter(nullptr)
{
    m_pFilter = make_shared<V2xRvFilter>();
    m_pRecvProxy = make_shared<V2xReceiverProxy>();
    m_recycleResourcePool.setSize(100);
}

void V2xReceiver::Run()
{
    TraceL << "V2xReceiver Thread Start" << endl;
   // m_pVmfReceiver = make_shared<V2xVmfReceiver>();

   // m_pVmfReceiver->Start();
    m_pRecvProxy->Init();

    V2xMsg::ValuePtr msg = m_recycleResourcePool.obtain();

    // if no data, recv will block
    while (m_pRecvProxy->Recv(move(msg))) {

        distribute(std::move(msg));
        // 获取一个msg
        msg = m_recycleResourcePool.obtain();
    }

}
V2xReceiver::~V2xReceiver()
{

}

}
