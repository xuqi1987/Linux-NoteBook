cmake_minimum_required(VERSION 3.13)
project(01_CppPrimer)

set(CMAKE_CXX_STANDARD 14)

include_directories(./src)
include_directories(./test)

add_executable(01_CppPrimer
        main.cpp
        src/Util/logger.cpp src/Util/logger.h src/Util/util.cpp src/Util/util.h test/LoggerTest.cpp test/LoggerTest.h)
TARGET_LINK_LIBRARIES(01_CppPrimer
        pthread
        )