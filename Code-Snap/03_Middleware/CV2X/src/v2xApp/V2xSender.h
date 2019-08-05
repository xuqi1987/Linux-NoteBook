//
// Created by xuqi on 2019-07-22.
//

#ifndef V2XSENDER_H
#define V2XSENDER_H
#include "v2xUtil/V2xThread.h"
#include "V2xScene.h"

namespace v2x {
class V2xSender : public V2xThread
{
public:
    typedef shared_ptr<V2xSender> Ptr;
    void run() override;

    void setSceneQueue(V2xScene::Queue::Ptr &sceneQueue);
private:
    V2xScene::Queue::Ptr _scene_queue;
};


}
#endif //V2XSENDER_H
