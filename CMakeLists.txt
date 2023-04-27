cmake_minimum_required(VERSION 3.25)
project(team_maker)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} "-static")

add_executable(team_maker main.cpp tabulate/tabulate.hpp header/Player.h header/Team.h)
