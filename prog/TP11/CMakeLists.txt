cmake_minimum_required(VERSION 2.6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -fno-elide-constructors")
set(SOURCE_FILES cyclicnode.h liste.hh copier.h main.cpp)

add_executable(tests ${SOURCE_FILES})
