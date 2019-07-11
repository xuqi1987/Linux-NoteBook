#include <iostream>
#include "Util/logger.h"

using namespace toolkit;

int main()
{
    Logger::Instance().add(make_shared<ConsoleChannel>());
    
    WarnL << "hello";
    std::cout << "Hello, World!" << std::endl;

    return 0;
}