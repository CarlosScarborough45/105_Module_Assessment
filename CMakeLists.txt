cmake_minimum_required(VERSION 3.20)
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
        WaitStaff.cpp
)

target_link_options(backend_00P PRIVATE -static-libgcc -static-libstdc++)

find_package(unofficial-sqlite3 CONFIG REQUIRED)
target_link_libraries(backend_00P PRIVATE unofficial::sqlite3::sqlite3)