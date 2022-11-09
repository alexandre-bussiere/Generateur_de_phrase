cmake_minimum_required(VERSION 3.21)
project(Generateur_de_phrase C)

set(CMAKE_C_STANDARD 99)

add_executable(Generateur_de_phrase main.c struct.h tree.c tree.h)
