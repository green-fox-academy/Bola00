cmake_minimum_required(VERSION 3.13)
project(Aircraft_Carrier)

set(CMAKE_CXX_STANDARD 14)

add_executable(Aircraft_Carrier main.cpp aircraft.cpp aircraft.h F16.cpp F16.h F35.cpp F35.h Carrier.cpp Carrier.h)