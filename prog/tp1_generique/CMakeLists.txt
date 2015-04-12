cmake_minimum_required(VERSION 2.8.4)
project(prog_cpp_generique)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

set(SOURCE_FILES ../tp1/memory.cxx vecteur.h vecteur.cpp main.cpp)
add_executable(prog_cpp ${SOURCE_FILES})
