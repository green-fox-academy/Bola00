cmake_minimum_required(VERSION 3.12)

# Change this to the name of the directory that contains your code
set(PROJECT_LIB_NAME apples_lib)

# Change this to the name of the directory that contains your tests
set(PROJECT_TESTS_NAME apples_tests)

# Change this to the path where you extracted the Google Test files to
set(PATH_TO_GOOGLETEST "C:/Important stuff/googletest")

# Change this to your project name (optional)
set(PROJECT_NAME Apples)


project(${PROJECT_NAME})
set(CMAKE_CXX_STANDARD 14)

# The next line creates an executable file from main.cpp with the same name as your project
add_executable(${PROJECT_NAME} main.cpp)

# This block includes the subdirectories containing your code and tests
include_directories(${PROJECT_LIB_NAME})
add_subdirectory(${PROJECT_LIB_NAME})
add_subdirectory(${PROJECT_TESTS_NAME})
