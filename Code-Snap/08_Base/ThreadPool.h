//
// Created by xuqi on 2019-06-17.
//

#ifndef THREADPOOL_H
#define THREADPOOL_H
#include <vector>
#include <queue>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <functional>
#include <stdexcept>


//#define C11
#define C14

class ThreadPool
{
public:
    ThreadPool(size_t);

#ifdef C14
    template<class F,class... Args>
    auto enqueue(F&& f,Args&&... args);
#endif

#ifdef C11
    template<class F, class... Args>
    auto enqueue(F&& f, Args&&... args)
    -> std::future<typename std::result_of<F(Args...)>::type>;
#endif
    ~ThreadPool();

private:
    // 线程池
    std::vector< std::thread > workers;
    // 任务队列
    std::queue< std::function<void()> > tasks;

    // synchronization同步
    std::mutex queue_mutex;
    std::condition_variable condition;
    bool stop;
};


#endif //THREADPOOL_H
