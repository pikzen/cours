cmake_minimum_required(VERSION 2.6)

set(CMAKE_CXX_COMPILER "g++-4.9")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fno-elide-constructors -fdiagnostics-color=always")
set(SOURCE_FILES ../src/client.cc
				 ../src/ferry.h ../src/ferry.cc
				 ../src/vehicule.h ../src/vehicule.cc
				 ../src/tcomparator.h
				 ../src/comparerlongueurvehicule.h ../src/comparerlongueurvehicule.cc
				 ../src/comparerpassagersvehicule.h ../src/comparerpassagersvehicule.cc
				 ../src/auto.h ../src/auto.cc
				 ../src/bus.h ../src/bus.cc
				 ../src/ambulance.h ../src/ambulance.cc
				 ../src/cycle.h ../src/cycle.cc
	)

add_executable(ferry ${SOURCE_FILES})
