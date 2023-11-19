cmake_minimum_required(VERSION 3.14)

project(hello_cmake
    VERSION 0.1.0
    DESCRIPTION "Hello, CMake!"
    LANGUAGES CXX)

add_executable(main main.cxx)
target_compile_features(main PRIVATE cxx_std_20)
