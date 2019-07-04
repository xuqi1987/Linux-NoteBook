//
// Created by xuqi on 2019-07-02.
//

#include "util.h"

namespace toolkit {

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

}