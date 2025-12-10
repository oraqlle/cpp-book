cmake_minimum_required(VERSION 3.22)

project(hello_world
    VERSION 0.1.0
    DESCRIPTION "Hello, CMake!"
    LANGUAGES CXX)

add_executable(hello_world main.cxx)
target_compile_features(hello_world PRIVATE cxx_std_17)
