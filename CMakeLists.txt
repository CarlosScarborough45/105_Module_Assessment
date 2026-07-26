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

target_link_options(backend_00P PRIVATE -static-libgcc -static-libstdc++ -static)

find_package(SQLite3 REQUIRED)
target_include_directories(backend_00P PRIVATE third_party/sqlite)
target_link_libraries(backend_00P PRIVATE SQLite::SQLite3)