#!/bin/bash

if [ -z "`cmake -version | grep Kitware`" ]; then
echo "=============install cmake ========================"
sudo apt-get install cmake
fi

rm -rf linux_build
mkdir -p linux_build
rm -rf ./build
ln -s ./linux_build build
cd linux_build

cmake .. -DForTest=ON
make -j4
