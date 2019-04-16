cmake_minimum_required(VERSION 3.13)
project(01 C)

SET(CMAKE_C_COMPILER   /home/zero/sdk/gcc-4.6.2-glibc-2.13-linaro-multilib-2011.12/fsl-linaro-toolchain/bin/arm-none-linux-gnueabi-gcc)
set(CMAKE_C_STANDARD 99)

add_executable(01 main.c)