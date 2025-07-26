cmake_minimum_required(VERSION 3.28)
project(libnpy)

set(CMAKE_CXX_FLAGS "-O3 -std=c++2b")

add_subdirectory(3rdparty/Catch2)

add_library(npy INTERFACE)

target_include_directories(npy
    INTERFACE include
)

add_executable(tests
    tests/test_tensor.cpp
)

target_link_libraries(tests
    PRIVATE Catch2::Catch2WithMain
    PRIVATE npy
)

include(CTest)
include(Catch)
catch_discover_tests(tests)
