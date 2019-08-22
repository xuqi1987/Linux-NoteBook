//
// Created by xuqi on 2019-07-22.
//

#ifndef V2XSENDER_H
#define V2XSENDER_H
#include "V2xThread.h"
#include "V2xSceneMsg.h"

namespace v2x {
class V2xSender : public V2xThread
{
public:
    typedef shared_ptr<V2xSender> Ptr;
    void Run() override;

    void SetSceneQueue(V2xSceneMsg::Queue::Ptr &pSceneQueue);
private:
    V2xSceneMsg::Queue::Ptr m_pSceneQueue;
};


}
#endif //V2XSENDER_H
