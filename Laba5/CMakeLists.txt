cmake_minimum_required(VERSION 3.7)
project(Laba5)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c Source/Stack.c Header/Stask.h Source/List.c Header/List.h)
add_executable(Laba5 ${SOURCE_FILES})