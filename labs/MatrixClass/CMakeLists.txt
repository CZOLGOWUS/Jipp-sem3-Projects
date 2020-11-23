cmake_minimum_required(VERSION 3.16.3)

project(MatrixClass VERSION 1.0.0)

add_executable(${PROJECT_NAME} ./src/main.cpp ./src/Matrix.cpp)


#----------------------------------------------------------tell compiler which libraries to include you want-----------------------
#
include_directories( PUBLIC ./include/lab4 PRIVATE ./src)