cmake_minimum_required(VERSION 3.13)
project(03_ARM)

#set(CMAKE_CXX_STANDARD 11)

SET(TOOLSCHAIN_PATH /home/zero/sdk/gcc-4.6.2-glibc-2.13-linaro-multilib-2011.12/fsl-linaro-toolchain/)
set(TOOLCHAIN_HOST "${TOOLSCHAIN_PATH}bin/arm-none-linux-gnueabi")

set(TOOLCHAIN_CC "${TOOLCHAIN_HOST}-gcc")
set(TOOLCHAIN_CXX "${TOOLCHAIN_HOST}-g++")

#告诉cmake是进行交叉编译
set(CMAKE_CROSSCOMPILING TRUE)

#set(CMAKE_C_STANDARD 11)
# Define the compiler
set(CMAKE_C_COMPILER ${TOOLCHAIN_CC})
set(CMAKE_CXX_COMPILER ${TOOLCHAIN_CXX})

add_executable(03_ARM main.cpp)

## include head file
#include_directories(EOL/src)
#include_directories(EOL/src/protected)
#
#include_directories(../ai-sdk-forMiddleware-NGI/config/include/)
#include_directories(../ai-sdk-forMiddleware-NGI/lib_config/include/)
#include_directories(../ai-sdk-forMiddleware-NGI/hal/include/)
#include_directories(../ai-sdk-forMiddleware-NGI/osal/include/)
#include_directories(../ai-sdk-forMiddleware-NGI/vmf_client/include/)
#include_directories(../ai-sdk-forMiddleware-NGI/vmf_trace/include/)
#include_directories(../ai-sdk-forMiddleware-NGI/power_agent/include/)
#include_directories(../ai-sdk-forMiddleware-NGI/audio/include/)
#include_directories(../ai-sdk-forMiddleware-NGI/KeyControl/include/)
#include_directories(../ai-sdk-forMiddleware-NGI/pss/include/)
#include_directories(../ai-sdk-forMiddleware-NGI/tuner_proxy/include/)
#include_directories(../ai-sdk-forMiddleware-NGI/vr_client/include/)
#include_directories(../ai-sdk-forMiddleware-NGI/pss/include/)
#include_directories(../ai-sdk-forMiddleware-NGI/Diagnostics/include)
#include_directories(../ai-sdk-forMiddleware-NGI/lib_config/include/)
#include_directories(../ai-sdk-forMiddleware-NGI/config/include/)
#include_directories(../ai-sdk-forMiddleware-NGI/osal/include/)
#include_directories(../ai-sdk-forMiddleware-NGI/mediainclude)
#
#
## include lib
#link_directories(../ai-sdk-forMiddleware-NGI/lib_config/lib/)
#link_directories(../ai-sdk-forMiddleware-NGI/hal/lib/)
#link_directories(../ai-sdk-forMiddleware-NGI/osal/lib/)
#link_directories(../ai-sdk-forMiddleware-NGI/vmf_client/lib/)
#link_directories(../ai-sdk-forMiddleware-NGI/vmf_trace/lib/)
#
#set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
#
#add_executable(EOL
#        EOL/src/protected/debug.h
#        EOL/src/protected/diag_eol_main.h
#        EOL/src/protected/diag_eol_rcv_c.h
#        EOL/src/protected/diag_eol_rcv_p.h
#        EOL/src/protected/diag_eol_state.h
#        EOL/src/protected/diag_eol_timer.h
#        EOL/src/protected/diag_eol_vmf_comm.h
#        EOL/src/protected/diag_eol_vmf_send.h
#        EOL/src/src/diag_eol_main.c
#        EOL/src/src/diag_eol_rcv.c
#        EOL/src/src/diag_eol_state.c
#        EOL/src/src/diag_eol_timer.c
#        EOL/src/src/diag_eol_vmf_comm.c
#        EOL/src/src/diag_eol_vmf_send.c
#        EOL/src/diag_eol_arm_if.h)
#
## link lib
#target_link_libraries(EOL CONFIG)
#target_link_libraries(EOL HAL)
#target_link_libraries(EOL OSAL)
#target_link_libraries(EOL vmf_client)
#target_link_libraries(EOL vmf_trace)