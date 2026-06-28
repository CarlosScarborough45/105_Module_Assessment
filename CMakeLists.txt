cmake_minimum_required(VERSION 4.2)
project(105Module)

set(CMAKE_CXX_STANDARD 20)

add_executable(105Module
        main.cpp
        Staff.cpp
        Manager.cpp
        Kitchen.cpp
        Admin.cpp
        Global.h)

target_link_options(105Module PRIVATE -static -static-libgcc -static-libstdc++)
