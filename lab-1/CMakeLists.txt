cmake_minimum_required(VERSION 4.3.2)
project(week-one-lab VERSION 4.3.2)

add_executable(hello_world)
target_sources(hello_world PRIVATE src/hello.cpp)
target_sources(hello_world PRIVATE src/name.cpp)

target_include_directories(hello_world PRIVATE include)