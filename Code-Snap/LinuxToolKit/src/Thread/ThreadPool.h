//
// Created by xuqi on 2019-07-11.
//

#ifndef LINUXTOOLKIT_SRC_THREAD_THREADPOOL_H_
#define LINUXTOOLKIT_SRC_THREAD_THREADPOOL_H_

#include <assert.h>
#include <vector>
#include "Thread/ThreadGroup.h"
#include "TaskQueue.h"
#include "TaskExecutor.h"
#include "Util/Util.h"
#include "Util/Logger.h"

namespace toolkit {

class ThreadPool : public TaskExecutor {
 public:

  typedef std::shared_ptr<ThreadPool> Ptr;
  enum Priority {
    PRIORITY_LOWEST = 0,
    PRIORITY_LOW,
    PRIORITY_NORMAL,
    PRIORITY_HIGH,
    PRIORITY_HIGHEST
  };

  //num:线程池线程个数
  ThreadPool(int num = 1,
             Priority priority = PRIORITY_HIGHEST,
             bool autoRun = true) :
      _thread_num(num), _priority(priority) {
    if (autoRun) {
      start();
    }
    // 线程池没析构，log不退出
    _logger = Logger::Instance().shared_from_this();
  }
  ~ThreadPool() {
    shutdown();
    wait();
  }

  //把任务打入线程池并异步执行，否则返回任务指针
  Task::Ptr async(TaskIn &&task, bool may_sync = true) override {
    if (may_sync && _thread_group.is_this_thread_in()) {
      task();
      return nullptr;
    }
    auto ret = std::make_shared<Task>(std::move(task));
    _queue.push_task(ret);
    return ret;
  }

  Task::Ptr async_first(TaskIn &&task, bool may_sync = true) override {
    if (may_sync && _thread_group.is_this_thread_in()) {
      task();
      return nullptr;
    }

    auto ret = std::make_shared<Task>(std::move(task));
    _queue.push_task_first(ret);
    return ret;
  }

  uint64_t size() {
    return _queue.size();
  }

  static bool setPriority(Priority priority = PRIORITY_NORMAL,
                          thread::native_handle_type threadId = 0) {

    static int Min = sched_get_priority_min(SCHED_OTHER);
    if (Min == -1) {
      return false;
    }
    static int Max = sched_get_priority_max(SCHED_OTHER);
    if (Max == -1) {
      return false;
    }
    static int Priorities[] = {Min, Min + (Max - Min) / 4, Min
        + (Max - Min) / 2, Min + (Max - Min) * 3 / 4, Max};

    if (threadId == 0) {
      threadId = pthread_self();
    }
    struct sched_param params;
    params.sched_priority = Priorities[priority];
    return pthread_setschedparam(threadId, SCHED_OTHER, &params) == 0;

  }

  void start() {
    if (_thread_num <= 0)
      return;
    auto total = _thread_num - _thread_group.size(); // 调整过Size后，需要更多的线程
    for (int i = 0; i < total; ++i) {
      _thread_group.create_thread(bind(&ThreadPool::run, this));
    }
  }

 private:
  void run() {
    ThreadPool::setPriority(_priority);
    Task::Ptr task;
    while (true) {
      startSleep();
      if (!_queue.get_task(task)) {
        //空任务，退出线程
        break;
      }
      sleepWakeUp();
      try {
        (*task)();
        task = nullptr;
      } catch (std::exception &ex) {
        ErrorL << "ThreadPool执行任务捕获到异常:" << ex.what();
      }
    }
  }

  void wait() {
    _thread_group.join_all();
  }

  void shutdown() {
    _queue.push_exit(_thread_num);
  }
 private:
  TaskQueue<Task::Ptr> _queue;
  ThreadGroup _thread_group;
  int _thread_num;
  Priority _priority;
  Logger::Ptr _logger;
};

} /* namespace toolkit */

#endif //LINUXTOOLKIT_SRC_THREAD_THREADPOOL_H_
