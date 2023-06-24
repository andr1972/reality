cmake_minimum_required(VERSION 3.23)
project(onthology)

set(CMAKE_CXX_STANDARD 14)

if(CMAKE_COMPILER_IS_GNUCXX)
    SET(GCC_COVERAGE_COMPILE_FLAGS "-Werror=return-type")
    add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})
endif()

add_executable(onthology main.cpp Brain.h Spiritual.h Matter.h Fundamental.h Live.h Brain.cpp
        Information.h Culture.h Spiritual.cpp)
