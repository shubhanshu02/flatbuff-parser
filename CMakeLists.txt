cmake_minimum_required(VERSION 3.10)

project(fparse LANGUAGES CXX)

add_executable(fparse src/main.cpp)

add_library(vwparser src/vwparser.hpp src/vwparser.cpp)

target_link_libraries(fparse PRIVATE vwparser)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


