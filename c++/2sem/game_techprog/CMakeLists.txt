cmake_minimum_required(VERSION 3.14)
project(game_techprog)

set(CMAKE_CXX_STANDARD 14)

add_executable(game_techprog main.cpp main.h units/unit.cpp units/unit.h map/map.cpp map/map.h)