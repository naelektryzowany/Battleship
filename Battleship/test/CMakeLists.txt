cmake_minimum_required(VERSION 3.7)
project(Battleships)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

include_directories("inc" "../inc")
file(GLOB SOURCES "src/*.cc" "../src/*.cc")
list(FILTER SOURCES EXCLUDE REGEX  ".*main.cc$")
set(PThreadLib -pthread)
add_executable(game ${SOURCES})
target_link_libraries(game ${GTEST_BOTH_LIBRARIES} ${PThreadLib})
