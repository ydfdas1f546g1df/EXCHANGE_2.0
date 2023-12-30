cmake_minimum_required(VERSION 3.26 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 11)

project(EXCHANGE2.0_MAAS LANGUAGES CXX)
project(EXCHANGE2.0_MAAC)
project(EXCHANGE2.0_MTAS)




if (CMAKE_BUILD_TYPE MATCHES Debug)
    add_definitions(-DDEBUG=1)
endif()

include_directories(include)
add_executable(EXCHANGE2.0_MAAS src/MAAS/main.cpp

        include/Logger/Logger.cpp
)
add_executable(EXCHANGE2.0_MTAS src/MTAS/main.cpp
        include/Logger/Logger.cpp
)
add_executable(EXCHANGE2.0_MTAC src/MTAC/main.cpp
        include/Logger/Logger.cpp
)
