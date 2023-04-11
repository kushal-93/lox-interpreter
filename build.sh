#!/bin/sh

rm -rf build
rm -rf CMakeCache.txt
rm -rf CMakeFiles
rm -rf cmake_install.cmake
rm -rf Makefile

cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug