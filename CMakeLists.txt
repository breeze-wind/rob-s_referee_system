cmake_minimum_required(VERSION 3.30)
project(robomaster_caipanmoni)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
add_executable(robomaster_caipanmoni main.cpp
        robots.cpp
        robots.h
        teams.cpp
        teams.h
        manage.cpp
        manage.h
)
