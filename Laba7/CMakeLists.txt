cmake_minimum_required(VERSION 3.7)
project(Laba7)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Source/Quiz.cpp Header/Quiz.h Header/json.hpp Header/Topic.hpp Header/Question.hpp)
add_executable(Laba7 ${SOURCE_FILES})