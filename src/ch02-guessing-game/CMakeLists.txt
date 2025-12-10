cmake_minimum_required(VERSION 3.22)

project(guessing_game
    VERSION 0.1.0
    DESCRIPTION "Number Guessing Game"
    LANGUAGES CXX)

add_executable(guessing_game main.cxx)
target_compile_features(guessing_game PRIVATE cxx_std_17)

if (MSVC)
    # warning level 4
    add_compile_options(/W4)
else()
    # additional warnings
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()
