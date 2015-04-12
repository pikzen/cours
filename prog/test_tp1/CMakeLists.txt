cmake_minimum_required(VERSION 2.6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -fno-elide-constructors -g")
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
file(GLOB vecteur_src
				"*.h"
				"*.cpp"
)
add_executable(tests test_vecteur.cc vecteur.h vecteur.cpp)
target_link_libraries(tests ${GTEST_LIBRARIES} pthread)
