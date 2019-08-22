//
// Created by root on 19-7-11.
//

#ifndef CV2X_DATAPOOL_H
#define CV2X_DATAPOOL_H
#include <queue>
#include <mutex>
#include "Util/Util.h"
#include "Thread/semaphore.h"

using namespace toolkit;

namespace v2x {

template <typename T>
class V2xMsgQueue : public std::enable_shared_from_this<V2xMsgQueue<T> > , public noncopyable
{
public:

    typedef shared_ptr<V2xMsgQueue<T> > Ptr;
    template <typename C>
    void push(C &&data) {
        {
            lock_guard<decltype(_mutex)> lock(_mutex);
            _queue.emplace(std::forward<C>(data));
        }
        _sem.post();
    }

    /**
     * this funciton will block,until data push
     * @tparam C
     * @param data
     * @return
     */
    template <typename C>
    bool pop(C &data) {
        _sem.wait();
        lock_guard<decltype(_mutex)> lock(_mutex);

        if (_queue.size() == 0) {
            return  false;
        }
        data = std::move(_queue.front());
        _queue.pop();
        return true;
    }

private:
    std::queue<T> _queue;
    mutable mutex _mutex;
    semaphore _sem;

};

}

#endif //CV2X_DATAPOOL_H
