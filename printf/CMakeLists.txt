cmake_minimum_required(VERSION 3.13)  # CMake version check
project(libft)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

# Add main.cpp file of project root directory as source file
FILE(GLOB MyCSources ./**/*.c ./**/*.h ./src/*.c ./src/*.h ./src/libft/*.c ./src/libft/*.h)
set(SOURCE_FILES main.c ${MyCSources})

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(libft ${SOURCE_FILES})
