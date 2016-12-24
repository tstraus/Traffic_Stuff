cmake_minimum_required(VERSION 3.6)
project(Traffic_Stuff)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Vehicle.cpp Vehicle.h)
add_executable(Traffic_Stuff ${SOURCE_FILES})