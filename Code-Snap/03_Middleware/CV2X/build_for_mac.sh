#!/bin/bash


mkdir -p mac_build
rm -rf ./build
ln -s ./mac_build build
cd mac_build

cmake ..
make -j4
