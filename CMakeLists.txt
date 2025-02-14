cmake_minimum_required(VERSION 3.29)
project(rsg)
project(testapp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(rsg SHARED
    "${CMAKE_SOURCE_DIR}/src/rsg.cpp"
    "${CMAKE_SOURCE_DIR}/src/rules.cpp"
    "${CMAKE_SOURCE_DIR}/src/charset.cpp"
)
target_include_directories(rsg PRIVATE "${CMAKE_SOURCE_DIR}/")

add_executable(testapp
    "${CMAKE_SOURCE_DIR}/testapp/src/main.cpp"
)
target_include_directories(testapp PRIVATE "${CMAKE_SOURCE_DIR}/testapp/")
target_link_libraries(testapp PRIVATE rsg)
