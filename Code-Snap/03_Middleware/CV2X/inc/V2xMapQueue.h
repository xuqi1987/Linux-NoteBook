//
// Created by root on 19-8-8.
//

#ifndef CV2X_V2XMAPHISTORYQUEUE_H
#define CV2X_V2XMAPHISTORYQUEUE_H

#include <queue>
#include <mutex>
#include "Util/Util.h"
#include "Thread/semaphore.h"

using namespace toolkit;

namespace v2x
{

template <typename T>
class V2xMapQueue: public std::enable_shared_from_this<V2xMapQueue<T> > , public noncopyable
{
public:
    typedef shared_ptr<V2xMapQueue<T> > Ptr;
};
}


#endif //CV2X_V2XMAPHISTORYQUEUE_H
