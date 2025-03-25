cmake_minimum_required(VERSION 3.30)
project(MyCpp3_Classes)

set(CMAKE_CXX_STANDARD 20)

add_executable(MyCpp3_Classes main.cpp
        Rectangle.cpp
        Rectangle.h
        TextBox.cpp
        TextBox.h)
