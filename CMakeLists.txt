cmake_minimum_required(VERSION 3.27)
project(AdventOfCode)

set(CMAKE_CXX_STANDARD 17)

add_executable(AdventOfCode main.cpp
        day01/day01.cpp
        day01/day01.h
        day02/day02.cpp
        day02/day02.h
        day03/day03.cpp
        day03/day03.h)

file(GLOB INPUT_FILES "inputs/*.txt")
file(COPY ${INPUT_FILES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
