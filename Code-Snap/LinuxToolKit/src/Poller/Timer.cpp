
#include "Timer.h"

namespace toolkit
{

Timer::Timer(float second,
             const function<bool()> &cb,
             const EventPoller::Ptr &poller,
             bool continueWhenException)
{
    _poller = poller;
    if (!_poller) {
        _poller = EventPollerPool::Instance().getPoller();
    }
    _tag = _poller->doDelayTask(second * 1000, [cb, second, continueWhenException]()
    {
        try {
            if (cb()) {
                //重复的任务
                return (uint64_t) (1000 * second);
            }
            //该任务不再重复
            return (uint64_t) 0;
        }
        catch (std::exception &ex) {
            ErrorL << "执行定时器任务捕获到异常:" << ex.what();
            return continueWhenException ? (uint64_t) (1000 * second) : 0;
        }
    });
}

Timer::~Timer()
{
    _tag->cancel();
}

}  // namespace toolkit
