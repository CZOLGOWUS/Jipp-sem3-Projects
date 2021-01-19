cmake_minimum_required(VERSION 3.16.3)
project(project VERSION 1.0.0)

include_directories(./include ./src)

#add_library(
#    table
#    include/table.hpp
#    src/table.cpp
#)
#
#add_library(
#    philosopher
#    include/philosopher.hpp
#    src/philosopher.cpp
#)

find_package(Threads)

add_executable(dine src/main.cpp src/philosopher.cpp src/table.cpp)

target_link_libraries(dine ${CMAKE_THREAD_LIBS_INIT})
#target_link_libraries(dine PUBLIC table PUBLIC philosopher)
