cmake_minimum_required (VERSION 2.6)
SET(CMAKE_CXX_FLAGS "--std=c++17") #Turn on C++17 Support
set(CMAKE_CXX_FLAGS "-O3 -Wall -Wextra")

project (rpn)

include_directories(
    /usr/include
    /home/pukala/Desktop/Academy
    )


add_executable(rpn 
    main.cpp
    /home/pukala/Desktop/Academy/RpnCalculator.cpp
    )