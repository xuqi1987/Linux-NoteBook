//
// Created by xuqi on 2019-07-02.
//

#include <ostream>
#include <string>
#include "Util/Logger.h"

using namespace std;
using namespace toolkit;

namespace test
{
class LoggerTest
{
 public:
  virtual ~LoggerTest();
  LoggerTest(){};
  LoggerTest(const string &name);
  static LoggerTest &Instance();
  void demo();

};

}
namespace test
{
INSTANCE_IMP(LoggerTest,string("Log"))
void LoggerTest::demo()
{
    ErrorL << "hello"<<"aaa"<<"bbbb";
}
LoggerTest::~LoggerTest()
{
    cout << "\n~LoggerTest" << endl;
}
LoggerTest::LoggerTest(const string &name)
{
    Logger::Instance().add(std::make_shared<ConsoleChannel>());
    Logger::Instance().add(std::make_shared<FileChannel>());
    Logger::Instance().add(std::make_shared<SysLogChannel>());
   // cout << "LoggerTest:" << name <<endl;
   cout << endl;
}
}


using  namespace test;
int main()
{
  LoggerTest::Instance().demo();

  return 0;

}
