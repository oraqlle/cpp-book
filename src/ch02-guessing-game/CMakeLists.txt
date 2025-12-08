cmake_minimum_required(VERSION 3.14)

project(guessing_game
    VERSION 0.1.0
    DESCRIPTION "Number Guessing Game"
    LANGUAGES CXX)

add_executable(guessing_game main.cxx)
target_compile_features(guessing_game PRIVATE cxx_std_20)

