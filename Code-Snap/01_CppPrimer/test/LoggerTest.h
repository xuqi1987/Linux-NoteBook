//
// Created by xuqi on 2019-07-02.
//

#ifndef LOGGERTEST_H
#define LOGGERTEST_H
#include <ostream>
#include <string>
#include "Util/logger.h"

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


#endif //LOGGERTEST_H
