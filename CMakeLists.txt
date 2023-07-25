cmake_minimum_required(VERSION 3.25)
project(todo_list)

set(CMAKE_CXX_STANDARD 17)

add_executable(todo_list src/main.cpp src/Task.cpp src/Task.h src/Menu.cpp src/Menu.h)
