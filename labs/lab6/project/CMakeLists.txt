cmake_minimum_required(VERSION 3.16.3)
project(project VERSION 1.0.0)

include_directories(./include/lab6 ./src)

add_library(
    Employee
    include/lab6/Employee.h
    ./src/Employee.cpp
)

add_library(
    HRMS
    include/lab6/HRMS.h
    ./src/HRMS.cpp
)

add_executable(prog ./src/main.cpp)

target_link_libraries(prog PUBLIC Employee PUBLIC HRMS)