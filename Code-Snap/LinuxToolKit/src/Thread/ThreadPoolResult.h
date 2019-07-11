//
// Created by xuqi on 2019-07-11.
//

#ifndef CV2X_3RDPART_LINUXTOOLKIT_SRC_THREAD_THREADPOOLRESULT_H_
#define CV2X_3RDPART_LINUXTOOLKIT_SRC_THREAD_THREADPOOLRESULT_H_

#include <vector>
#include <queue>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <functional>
#include <stdexcept>

namespace toolkit {

class ThreadPoolResult {
 public:
  ThreadPoolResult(size_t);

  template<class F, class... Args>
  auto enqueue(F &&f, Args &&... args)
  -> std::future<typename std::result_of<F(Args...)>::type>;

  ~ThreadPoolResult();

 private:
  // 线程池
  std::vector<std::thread> workers;
  // 任务队列
  std::queue<std::function<void()> > tasks;

  // synchronization同步
  std::mutex queue_mutex;
  std::condition_variable condition;
  bool stop;
};

}

#endif //CV2X_3RDPART_LINUXTOOLKIT_SRC_THREAD_THREADPOOLRESULT_H_
