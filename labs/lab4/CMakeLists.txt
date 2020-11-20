cmake_minimum_required(VERSION 3.16.3)

project(lab4)

add_executable(${PROJECT_NAME} src/main.cpp)


#----------------------------------------------------------builds library----------------------------------------------------------
#
add_subdirectory(include/lab4)

#----------------------------------------------------------tell compiler which libraries to include you want-----------------------
#----------------------------------------------------------makes it soo we can use <library.h> instead of "project_name/lib_folder"
#
target_include_directories(${PROJECT_NAME} PRIVATE include/lab4)

#---------------------------------------------------------tell compiler where libraries you want to link/include are--------------
#
target_link_directories(${PROJECT_NAME} PRIVATE include/lab4)

#---------------------------------------------------------links libaries to executable-----------------------------------------------
#
target_link_libraries(${PROJECT_NAME} matrix)