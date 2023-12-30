cmake_minimum_required(VERSION 3.10)
project(computeStatistics)

#include_directories(/home/tom/prog/_lib/)
find_package(Boost REQUIRED COMPONENTS program_options math_c99)
if (NOT Boost_FOUND)
    message(FATAL_ERROR "Boost is required to build the program.")
endif()

include_directories(${Boost_INCLUDE_DIRS})
add_executable(computeStatistics computeStatistics.cxx)
target_link_libraries(computeStatistics ${Boost_LIBRARIES})
