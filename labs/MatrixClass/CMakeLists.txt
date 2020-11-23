cmake_minimum_required(VERSION 3.16.3)

project(MatrixClass VERSION 1.0.0)

add_executable(${PROJECT_NAME} ./src/main.cpp ./src/Matrix.cpp)


#----------------------------------------------------------tell compiler which libraries to include you want-----------------------
#----------------------------------------------------------makes it soo we can use <library.h> instead of <project_name/lib_folder
#
include_directories( PRIVATE ./include/lab4 PUBLIC ./src)