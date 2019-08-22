
#ifndef CV2X_V2XAPP_H
#define CV2X_V2XAPP_H

/////////////////////////////////////////////////////////
//
// File:
//
// V2xApp.h
//
// Purpose
//
// Definition of the V2xApp class
//
// File revision history: 0.1
//
// Date: 2019/08/20
// Reason of change: creation
// Author: qxu9
//
// Copyright Visteon Software Technologies
/////////////////////////////////////////////////////////


#include <iostream>
#include <memory>
#include <thread>
#include <future>
#include "Util/Logger.h"
#include "Util/ResourcePool.h"
#include "V2xMsgQueue.h"
#include "V2xMsg.h"
#include "Thread/ThreadPool.h"

#include "V2xRvAsyncFilter.h"
#include "V2xReceiver.h"
#include "V2xBroker.h"
#include "V2xSender.h"

#include "V2xMapQueue.h"

using namespace std;
using namespace v2x;
using namespace toolkit;

namespace v2x
{
class V2xApp
{
public:
  V2xApp();
    virtual ~V2xApp();
    void Run();

 private:

    V2xReceiver::Ptr m_pReceiver; // V2xReceiver Point

    /* V2xReceiver to V2xBroker data Queue */
    V2xMsg::Queue::Ptr m_pHvOutQueue;
    V2xMsg::Queue::Ptr m_pRvOutQueue;

    V2xBroker::Ptr m_pBroker; // V2xBroker Point

    /* V2xBroker to V2xSender data Queue */
    V2xSceneMsg::Queue::Ptr m_pSceneOutQueue;

    V2xSender::Ptr m_pSender; // V2xSender Point

};
}


#endif //CV2X_V2XAPP_H
