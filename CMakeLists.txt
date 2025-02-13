cmake_minimum_required(VERSION 3.29)
project(rsg)

set(CMAKE_CXX_STANDARD 17)

add_executable(rsg
    "${CMAKE_SOURCE_DIR}/src/rsg.cpp"
)
target_include_directories(rsg PRIVATE "${CMAKE_SOURCE_DIR}/")
