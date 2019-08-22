//
// Created by xuqi on 2019-07-13.
//

#ifndef CV2X_SRC_V2X_V2XFILTER_H_
#define CV2X_SRC_V2X_V2XFILTER_H_
#include <iostream>
#include <memory>
#include <thread>
#include <future>
#include "Util/Logger.h"
#include "Util/ResourcePool.h"
#include "V2xMsgQueue.h"
#include "V2xMsg.h"
#include "V2xThreadPool.h"

using namespace std;
using namespace v2x;
using namespace toolkit;
namespace v2x
{

class V2xRvAsyncFilter: public V2xThreadPool
{
public:
    void Run(int num) override;

    typedef shared_ptr<V2xRvAsyncFilter> Ptr;
    typedef ResourcePool<V2xMsg>::ValuePtr ValuePtr;
    typedef V2xMsgQueue<ValuePtr> Queue;

    V2xRvAsyncFilter(int iThreadNum, Queue::Ptr &pIn_Queue, Queue::Ptr &pOut_Queue);

private:
    Queue::Ptr m_pInputQueue;
    Queue::Ptr m_pOutputQueue;

};
}

#endif //CV2X_SRC_V2X_V2XFILTER_H_
