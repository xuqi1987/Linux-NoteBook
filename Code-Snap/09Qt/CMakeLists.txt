project(Gui)
cmake_minimum_required(VERSION 3.1.3)
#使能c++11
set(CMAKE_CXX_STANDARD 11)

# 自动调用moc，uic，rcc处理qt的扩展部分
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# 设置Qt5的cmake模块所在目录，如果不设置将使用系统提供的版本
# QT_DIR和QT_VERSION是指定了qt安装目录和版本的环境变量
# 如果你使用了系统的cmake，那么会优先使用系统提供模块，因为cmake会优先搜索CMAKE_SYSTEM_PREFIX_PATH
# 如果你不想让cmake优先搜索系统目录（会导致编译使用系统安装的qt而不是我们配置的），需要提示find_package命令
set(CMAKE_PREFIX_PATH  "/opt/Qt5.1.0/5.1.0/gcc_64/lib/cmake")


#设置库文件路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

#设置可执行程序路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

#设置工程源码根目录
set(GUI_Root ${CMAKE_SOURCE_DIR}/src/)


#设置头文件目录

INCLUDE_DIRECTORIES(${GUI_Root})


LINK_DIRECTORIES()

#收集源代码
file(GLOB GUI_Root_src_list ${GUI_Root}/*.cpp  ${GUI_Root}/*.h ${GUI_Root}/*.c)

message(STATUS "File:${GUI_Root_src_list}")

# 找到对应的qt模块，名字为qmake中QT += <name>中的name首字母大写后加上Qt5前缀
# 例如core为QtCore，你也可以去${CMAKE_PREFIX_PATH}的目录中找到正确的模块名
# 如果不想使用系统qt，这样写（注意NO_DEFAULT_PATH参数，它会让find_package跳过系统目录的查找）：
#find_package(Qt5Widgets REQUIRED NO_DEFAULT_PATH)

# 如果你想要使用系统自带的qt，这样写：
find_package(Qt5 COMPONENTS Core Widgets Network WebKitWidgets WebKit REQUIRED)

#打印库文件
message(STATUS "将链接依赖库:${LINK_LIB_LIST}")

add_executable(${CMAKE_PROJECT_NAME} ${GUI_Root_src_list})

#链接库
TARGET_LINK_LIBRARIES(${CMAKE_PROJECT_NAME} ${LINK_LIB_LIST})

# 把对应Qt模块的库链接进程序
TARGET_LINK_LIBRARIES(${CMAKE_PROJECT_NAME} Qt5::Widgets Qt5::WebKitWidgets Qt5::WebKit)



























