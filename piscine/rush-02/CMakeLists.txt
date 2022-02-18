cmake_minimum_required(VERSION 3.19)
project(rush-02 C)

set(CMAKE_C_STANDARD 99)

add_executable(rush-02 ex00/main.c ex00/string_utils.c ex00/file_utils.c ex00/array_utils.c ex00/math_utils.c ex00/dict_entry.c ex00/number_dict.c)