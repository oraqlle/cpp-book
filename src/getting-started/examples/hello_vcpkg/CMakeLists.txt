cmake_minimum_required(VERSION 3.14)

project(hello_vcpkg
    VERSION 0.1.0
    DESCRIPTION "Hello, vcpkg from {fmt}!"
    LANGUAGES CXX)

find_package(fmt CONFIG REQUIRED)

add_executable(hello_vcpkg main.cxx)
target_compile_features(hello_vcpkg PRIVATE cxx_std_20)

target_link_libraries(hello_vcpkg PRIVATE fmt::fmt)
