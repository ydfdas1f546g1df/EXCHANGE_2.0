cmake_minimum_required(VERSION 3.26 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

enable_testing()

project(EXCHANGE2.0_MAAS LANGUAGES CXX)
project(EXCHANGE2.0_MAAC LANGUAGES CXX)
project(EXCHANGE2.0_MTAS LANGUAGES CXX)




if (CMAKE_BUILD_TYPE MATCHES Debug)
    add_definitions(-DDEBUG=1)
endif()

include_directories(include)

add_subdirectory(src)
