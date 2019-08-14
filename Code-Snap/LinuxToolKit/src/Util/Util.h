//
// Created by xuqi on 2019-07-02.
//

#ifndef UTIL_H
#define UTIL_H
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <sys/time.h>

using namespace std;

namespace toolkit {

#define INSTANCE_IMP(class_name, args...) \
class_name & class_name::Instance() { \
    static auto s_pInst = std::make_shared<class_name>(args); \
    return *s_pInst; \
}

#define StrPrinter _StrPrinter()

class _StrPrinter : public string {
 public:
  _StrPrinter() {}

  template<typename T>
  _StrPrinter &operator<<(T &&data) { // 右值引用
    _stream << std::forward<T>(data); // 按照原有的类型转换
    this->string::operator=(_stream.str()); //调用基类的赋值函数，把值放在内部
    return *this;
  }

  string operator<<(std::ostream &(*f)(std::ostream &)) const {
    return *this;
  }

 private:
  stringstream _stream;
};

// 禁止拷贝构造函数
class noncopyable {
 protected:
  noncopyable() {};

  ~noncopyable() {};
 private:
  noncopyable(const noncopyable &that) = delete;

  noncopyable(noncopyable &&that) = delete;

  noncopyable &operator=(const noncopyable &that) = delete;

  noncopyable &operator=(noncopyable &&that) = delete;
};

string exePath();
string exeDir();
string exeName();

//去除前后的空格、回车符、制表符...
std::string &trim(std::string &s, const string &chars = " \r\n\t");
std::string trim(std::string &&s, const string &chars = " \r\n\t");
// string转小写
std::string &strToLower(std::string &str);
std::string strToLower(std::string &&str);
// string转大写
std::string &strToUpper(std::string &str);
std::string strToUpper(std::string &&str);
void replace(string &str, const string &old_str, const string &new_str);

/**
 * 获取1970年至今的毫秒数
 * @return
 */
uint64_t getCurrentMillisecond();

/**
 * 获取1970年至今的微秒数
 * @return
 */
uint64_t getCurrentMicrosecond();

}

#endif //UTIL_H
