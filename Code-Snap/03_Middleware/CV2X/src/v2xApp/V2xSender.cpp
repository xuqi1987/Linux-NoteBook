//
// Created by xuqi on 2019-07-22.
//

#include "V2xSender.h"
#include "V2xScene.h"

namespace v2x {
void V2xSender::run()
{
    V2xScene::ValuePtr scene;

    while(_scene_queue->pop(scene))
    {
        InfoL << *scene;
        scene.reset();
    }
}
void V2xSender::setSceneQueue(V2xScene::Queue::Ptr &sceneQueue)
{
    _scene_queue = sceneQueue;
}
}

