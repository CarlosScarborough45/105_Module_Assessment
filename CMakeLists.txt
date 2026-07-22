cmake_minimum_required(VERSION 4.1.2)
project(backend_00P)

set(CMAKE_CXX_STANDARD 20)

add_executable(backend_00P main.cpp
        Users.h
        User.cpp
        Manager.cpp
        Manager.h
        Tables.cpp
        Tables.h
        Admin.cpp
        Admin.h
        Customer.cpp
        Customer.h
        Staff.cpp
        Staff.h
        Menu.cpp
        Menu.h
)