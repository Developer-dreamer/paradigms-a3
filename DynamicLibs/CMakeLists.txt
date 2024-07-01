cmake_minimum_required(VERSION 3.28)
project(untitled1)

#set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

add_executable(DynamicLibs main.cpp
        CaesarAlgorythm.cpp
)
