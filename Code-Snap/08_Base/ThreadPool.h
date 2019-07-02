#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <vector>
#include <queue>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <functional>
#include <stdexcept>

class ThreadPool {
public:
    ThreadPool(size_t);
    template<class F, class... Args>
    auto enqueue(F&& f, Args&&... args) 
        -> std::future<typename std::result_of<F(Args...)>::type>;
    ~ThreadPool();
private:
    // need to keep track of threads so we can join them
    std::vector< std::thread > workers;
    // the task queue
    std::queue< std::function<void()> > tasks;
    
    // synchronization
    std::mutex queue_mutex;
    std::condition_variable condition;
    bool stop;
};
 
// the constructor just launches some amount of workers
inline ThreadPool::ThreadPool(size_t threads)
    :   stop(false)
{
    for(size_t i = 0;i<threads;++i) // 创建n个线程，每个线程等待是否有新的task, 或者线程stop（要终止）
        workers.emplace_back( // 构造并插入vector最后
            [this]
            {
                for(;;)
                {
                    std::function<void()> task;

                    {
                        std::unique_lock<std::mutex> lock(this->queue_mutex); // 获取同步锁
                        this->condition.wait(lock,
                            [this]{ return this->stop || !this->tasks.empty(); }); // 线程会一直阻塞，直到有新的task，或者是线程要退出
                        if(this->stop && this->tasks.empty()) // 线程退出
                            return;
                        task = std::move(this->tasks.front()); // 将task取出
                        this->tasks.pop();  // 队列中移除以及取出的task
                    }

                    task(); // 执行task,完了则进入下一次循环
                }
            }
        );
}

// 将队列压入线程池,其中f是要执行的函数， args是多有的参数
template<class F, class... Args> // 可变模版参数函数
auto ThreadPool::enqueue(F&& f, Args&&... args) // &&右值引用
    -> std::future<typename std::result_of<F(Args...)>::type> // 拖尾类型返回
{
    // 返回的结果的类型，当然可以根据实际的需要去掉这个(gcc4.7的c++11不支持)
    using return_type = typename std::result_of<F(Args...)>::type; // 相当于：typedef return_type typename std::result_of<F(Args...)>::type

    auto task = std::make_shared< std::packaged_task<return_type()> >(  // 使用智能指针构造packaged_task对象，参数使用bind 适配
            std::bind(std::forward<F>(f), std::forward<Args>(args)...) // std::bind通用的函数适配器,std::forward完美转发
        );
        
    std::future<return_type> res = task->get_future();
    {
        std::unique_lock<std::mutex> lock(queue_mutex);// 压入队列需要线程安全，因此需要先获取锁

        // don't allow enqueueing after stopping the pool
        if(stop)
            throw std::runtime_error("enqueue on stopped ThreadPool");

        tasks.emplace([task](){ (*task)(); }); // 任务压入队列
    }
    condition.notify_one();  // 添加了新的task，因此条件变量通知其他线程可以获取task执行
    return res;
}

// the destructor joins all threads
inline ThreadPool::~ThreadPool()
{
    {
        std::unique_lock<std::mutex> lock(queue_mutex); // 通知所有在等待锁的线程
        stop = true;
    }
    condition.notify_all(); // 等待所有的线程任务执行完成退出
    for(std::thread &worker: workers)
        worker.join();
}

#endif
