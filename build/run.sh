#!/bin/bash
cmake ..
make
./rpn
rm -rf CMakeCache.txt  CMakeFiles  Makefile  cmake_install.cmake rpn

