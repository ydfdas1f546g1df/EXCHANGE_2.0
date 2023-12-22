cmake_minimum_required(VERSION 3.26 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 11)

project(EXCHANGE2.0)

if (CMAKE_BUILD_TYPE MATCHES Debug)
    add_definitions(-DDEBUG=1)
endif()

include_directories(include)

add_executable(EXCHANGE2.0 src/main.cpp)