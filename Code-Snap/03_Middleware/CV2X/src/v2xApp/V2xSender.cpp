//
// Created by xuqi on 2019-07-22.
//

#include "V2xSender.h"
#include "V2xSceneMsg.h"

namespace v2x {
void V2xSender::Run()
{
    V2xSceneMsg::ValuePtr scene;

    while(m_pSceneQueue->pop(scene))
    {
        InfoL << *scene;
        scene.reset();
    }
}
void V2xSender::SetSceneQueue(V2xSceneMsg::Queue::Ptr &pSceneQueue)
{
    m_pSceneQueue = pSceneQueue;
}
}

