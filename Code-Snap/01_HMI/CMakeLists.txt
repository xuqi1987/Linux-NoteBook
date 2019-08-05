project(QTHMI)
cmake_minimum_required(VERSION 3.1.3)
#使能c++11
set(CMAKE_CXX_STANDARD 98)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH "/home/xuqi/proj/Private/Linux-NoteBook/Code-Snap/01_HMI/3rdpart/arm_qt5.1.0/")

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Core REQUIRED)


#设置库文件路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

#设置可执行程序路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

#设置工程源码根目录
set(QTHMI_Root ${CMAKE_SOURCE_DIR}/src/)



#设置头文件目录

INCLUDE_DIRECTORIES(${QTHMI_Root})


#收集源代码

file(GLOB QTHMI_src_list ${QTHMI_Root}/*.cpp ${QTHMI_Root}/*/*.cpp  ${QTHMI_Root}/*/*.h ${QTHMI_Root}/*/*.c ${QTHMI_Root}/*/*/*.cpp  ${QTHMI_Root}/*/*/*.h ${QTHMI_Root}/*/*/*.c)


#添加库
#add_library(toolkit STATIC ${ToolKit_src_list})


#set(LINK_LIB_LIST  toolkit asn1)

list(APPEND LINK_LIB_LIST pthread)
list(APPEND LINK_LIB_LIST Qt5::Widgets)
#打印库文件
message(STATUS "将链接依赖库:${LINK_LIB_LIST}")

add_executable(${CMAKE_PROJECT_NAME} ${QTHMI_src_list})

#链接库
TARGET_LINK_LIBRARIES(${CMAKE_PROJECT_NAME} ${LINK_LIB_LIST})

#测试程序
#add_subdirectory(tests)



























