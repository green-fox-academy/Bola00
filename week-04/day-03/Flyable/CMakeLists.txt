cmake_minimum_required(VERSION 3.13)
project(Flyable)

set(CMAKE_CXX_STANDARD 14)

add_executable(Flyable main.cpp flyable.h Animals.cpp Animals.h Bird.cpp Bird.h Vehicle.cpp Vehicle.h Helicopter.cpp Helicopter.h)