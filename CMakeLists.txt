cmake_minimum_required(VERSION 3.15)

project(computeStatistics
  LANGUAGES CXX
  HOMEPAGE_URL https://github.com/tlgf/computeStatistics
)

find_package(Boost REQUIRED)

if(NOT Boost_FOUND)
  message(ERROR: Boost Library not found)
  return()
endif()

add_executable(computeStatistics computeStatistics.cxx)
target_link_libraries(computeStatistics Boost::program_options)
