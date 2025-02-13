cmake_minimum_required(VERSION 3.29)
project(rsg)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(rsg SHARED
    "${CMAKE_SOURCE_DIR}/src/rsg.cpp"
)
target_include_directories(rsg PRIVATE "${CMAKE_SOURCE_DIR}/")
