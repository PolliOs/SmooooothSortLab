cmake_minimum_required(VERSION 3.20)
project(Lab_1)

set(CMAKE_CXX_STANDARD 14)

#add_executable(Lab_1 modified.cpp SmoooooothSort.cpp SmoooooothSort.h main.cpp)


find_package(benchmark REQUIRED)

set(modified.cpp SmoooooothSort.cpp SmoooooothSort.h main.cpp)
add_executable(Lab_1 modified.cpp SmoooooothSort.cpp SmoooooothSort.h Utils.cpp Utils.h)
add_executable(Lab_1_ram main.cpp  SmoooooothSort.cpp SmoooooothSort.h Utils.cpp Utils.h)


#set(SOURCE_FILES main.cpp)
#add_executable(factorials_run ${SOURCE_FILES})

#include_directories(factoriallib)
#add_subdirectory(factoriallib)
#target_link_libraries(factorials_run factoriallib_lib)

#add_subdirectory(factoriallib_benchmarks)