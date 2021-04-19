cmake_minimum_required(VERSION 3.17)
project(pneumatic_cylinder C)

set(CMAKE_C_STANDARD 90)

add_executable(pneumatic_cylinder main.c pneuma.h pneuma.c)