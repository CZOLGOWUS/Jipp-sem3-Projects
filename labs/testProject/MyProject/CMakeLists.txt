cmake_minimum_required(VERSION 3.16.3)

project(MyProject)

add_executable(${PROJECT_NAME} src/main.cpp)


#---------builds library----------------------------------------------------------
add_subdirectory(include)

#---------tell compiler which libraries to include you want-----------------------
#---------makes it soo we can use <library.h> instead of "project_name/lib_folder"
target_include_directories(${PROJECT_NAME} PRIVATE include)

#---------tell compiler where libraries you want to link/include are--------------
target_link_directories(${PROJECT_NAME} PRIVATE include)

#---------links adder to executable-----------------------------------------------
target_link_libraries(${PROJECT_NAME} adder)
