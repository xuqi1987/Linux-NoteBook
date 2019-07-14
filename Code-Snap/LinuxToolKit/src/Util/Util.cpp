//
// Created by xuqi on 2019-07-02.
//

#include <thread>
#include "Util.h"
#include "Logger.h"
#include "OnceToken.h"

using namespace std;
namespace toolkit {

#ifndef PATH_MAX
#define PATH_MAX 256
#endif

string exePath() {
  char buffer[PATH_MAX * 2 + 1] = {0};
  int n = -1;

  n = readlink("/proc/self/exe", buffer, sizeof(buffer));

  string filePath;
  if (n <= 0) {
    filePath = "./";
  } else {
    filePath = buffer;
  }

  return filePath;
}

string exeDir() {
  auto path = exePath();
  return path.substr(0, path.rfind('/') + 1);
}

string exeName() {
  auto path = exePath();
  return path.substr(path.rfind('/') + 1);
}

static inline uint64_t getCurrentMicrosecondOrigin() {
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return tv.tv_sec * 1000000LL + tv.tv_usec;

}

static atomic<uint64_t> s_currentMicrosecond(getCurrentMicrosecondOrigin());
static atomic<uint64_t> s_currentMillisecond(getCurrentMicrosecondOrigin() / 1000);

static inline bool initMillisecondThread() {
  static std::thread s_thread([]() {
    DebugL << "Stamp thread started!";
    uint64_t now;
    while (true) {
      now = getCurrentMicrosecondOrigin();
      s_currentMicrosecond.store(now, memory_order_release);
      s_currentMillisecond.store(now / 1000, memory_order_release);
      usleep(500);

    }
  });
  static OnceToken s_token([]() {
    s_thread.detach();
  });
  return true;
}

uint64_t getCurrentMillisecond() {
  static bool flag = initMillisecondThread();
  return s_currentMillisecond.load(memory_order_acquire);
}

uint64_t getCurrentMicrosecond() {
  static bool flag = initMillisecondThread();
  return s_currentMicrosecond.load(memory_order_acquire);
}

}