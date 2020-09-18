cmake_minimum_required(VERSION 3.17)
project(Game_of__life C)

set(CMAKE_C_STANDARD 99)

add_executable(Game_of__life life.c life_driver.c life.h)