cmake_minimum_required(VERSION 3.17)
project(GameOfLife C)

set(CMAKE_C_STANDARD 99)

add_executable(GameOfLife life.c life_driver.c)