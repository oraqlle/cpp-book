cmake_minimum_required(VERSION 3.14)

project(hello_cmake
    VERSION 0.1.0
    DESCRIPTION "Hello, CMake!"
    LANGUAGES CXX)

add_executable(hello_cmake main.cxx)
target_compile_features(hello_cmake PRIVATE cxx_std_20)
