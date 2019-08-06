//
// Created by xuqi on 2019-07-22.
//

#include "V2xSender.h"
#include "v2xUtil/V2xSceneMsg.h"

namespace v2x {
void V2xSender::run()
{
    V2xSceneMsg::ValuePtr scene;

    while(_scene_queue->pop(scene))
    {
        InfoL << *scene;
        scene.reset();
    }
}
void V2xSender::setSceneQueue(V2xSceneMsg::Queue::Ptr &sceneQueue)
{
    _scene_queue = sceneQueue;
}
}

