

#ifndef SEMAPHORE_H_
#define SEMAPHORE_H_

#include <atomic>
#include <mutex>
#include <condition_variable>
using namespace std;

namespace toolkit {

class semaphore {
 public:
  explicit semaphore(unsigned int initial = 0) {

    _count = 0;

  }
  ~semaphore() {

  }
  void post(unsigned int n = 1) {

    unique_lock<mutex> lock(_mutex);
    _count += n;
    if (n == 1) {
      _condition.notify_one();
    } else {
      _condition.notify_all();
    }

  }
  void wait() {

    unique_lock<mutex> lock(_mutex);
    while (_count == 0) {
      _condition.wait(lock);
    }
    --_count;

  }
 private:

  int _count;
  mutex _mutex;
  condition_variable_any _condition;

};

} /* namespace toolkit */

#endif /* SEMAPHORE_H_ */
