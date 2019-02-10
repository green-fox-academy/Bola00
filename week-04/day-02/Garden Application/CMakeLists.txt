cmake_minimum_required(VERSION 3.13)
project(Garden_Application)

set(CMAKE_CXX_STANDARD 14)

add_executable(Garden_Application main.cpp garden.cpp garden.h flower.cpp flower.h tree.cpp tree.h)