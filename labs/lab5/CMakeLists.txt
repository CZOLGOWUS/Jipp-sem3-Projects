cmake_minimum_required(VERSION 3.16.3)

project(lab5 VERSION 1.0.0)

add_executable(${PROJECT_NAME} ./src/main.cpp ./src/Matrix.cpp ./src/MatrixExeptions.cpp)


#----------------------------------------------------------tell compiler which libraries to include you want-----------------------
#
include_directories( PUBLIC ./include/lab5 PRIVATE ./src)