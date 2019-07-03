//
// Created by xuqi on 2019-07-02.
//

#include "LoggerTest.h"
namespace test
{
INSTANCE_IMP(LoggerTest,string("Log"))
void LoggerTest::demo()
{
    ErrorL << "hello" <<endl;
}
LoggerTest::~LoggerTest()
{
    cout << "\n~LoggerTest" << endl;
}
LoggerTest::LoggerTest(const string &name)
{
    Logger::Instance().add(std::make_shared<ConsoleChannel>());
   // cout << "LoggerTest:" << name <<endl;
   cout << endl;
}
}