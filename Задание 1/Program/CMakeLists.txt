cmake_minimum_required(VERSION 3.20)
project(Program)

set(CMAKE_CXX_STANDARD 20)

add_executable(Program main.cpp circle.cpp colour.cpp container.cpp rectangle.cpp triangle.cpp shape.cpp circle.h colour.h container.h rectangle.h shape.h triangle.h)
