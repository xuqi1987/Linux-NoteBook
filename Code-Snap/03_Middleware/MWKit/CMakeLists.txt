project(MWKit)
cmake_minimum_required(VERSION 3.1.3)
#使能c++11
set(CMAKE_CXX_STANDARD 11)

#设置库文件路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

#设置可执行程序路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

#设置工程源码根目录
set(ToolKit_Root ${CMAKE_SOURCE_DIR}/3rdpart/LinuxToolKit/src)
set(MWKit_Root ${CMAKE_SOURCE_DIR}/src)

#设置头文件目录
INCLUDE_DIRECTORIES(${ToolKit_Root})
INCLUDE_DIRECTORIES(${MWKit_Root})

#收集源代码
file(GLOB ToolKit_src_list ${ToolKit_Root}/*/*.cpp ${ToolKit_Root}/*/*.h ${ToolKit_Root}/*/*.c)
file(GLOB MWKit_src_list ${MWKit_Root}/*.cpp   ${MWKit_Root}/*.h ${MWKit_Root}/*.c)
message(STATUS "将链接依赖库:${MWKit_src_list}")

#添加库
add_library(toolkit STATIC ${ToolKit_src_list})

set(LINK_LIB_LIST  toolkit)

list(APPEND LINK_LIB_LIST pthread)
#打印库文件
message(STATUS "将链接依赖库:${LINK_LIB_LIST}")

add_executable(${CMAKE_PROJECT_NAME} ${MWKit_src_list})

#链接库
TARGET_LINK_LIBRARIES(${CMAKE_PROJECT_NAME} ${LINK_LIB_LIST})

#测试程序
add_subdirectory(tests)



























