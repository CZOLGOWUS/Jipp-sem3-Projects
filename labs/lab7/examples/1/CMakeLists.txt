cmake_minimum_required(VERSION 3.16.3)
project(project VERSION 1.0.0)

include_directories(./src ./include)

add_executable(main ./src/main.cpp)
