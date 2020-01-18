cmake_minimum_required(VERSION 3.7)
project(Battleships)

include_directories(inc)
file(GLOB SOURCES "src/*.cc")
add_executable(game ${SOURCES})
