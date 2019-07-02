//
// Created by xuqi on 2019-07-02.
//

#include "LoggerTest.h"
namespace test
{
INSTANCE_IMP(LoggerTest,string("aaa"))
void LoggerTest::check()
{
    cout << "check" << endl;
}
LoggerTest::~LoggerTest()
{
    cout << "~LoggerTest" << endl;
}
LoggerTest::LoggerTest(const string &name)
{
    cout << "LoggerTest:" << name <<endl;
}
}