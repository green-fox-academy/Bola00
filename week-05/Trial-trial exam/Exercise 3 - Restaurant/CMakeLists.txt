cmake_minimum_required(VERSION 3.13)
project(Exercise_3___Restaurant)

set(CMAKE_CXX_STANDARD 14)

add_executable(Exercise_3___Restaurant main.cpp employees.cpp employees.h restaurant.cpp restaurant.h waiter.cpp waiter.h chef.cpp chef.h manager.cpp manager.h)