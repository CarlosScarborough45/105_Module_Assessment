cmake_minimum_required(VERSION 3.10)
project(VisualApp LANGUAGES CXX)

add_executable(program
    main.cpp
    Users.cpp
    Admin.cpp
    Manager.cpp
    Menu.cpp
    Orders.cpp
    Table.cpp
    Users.cpp
    Waitstaff.cpp

    --Header Files
    Headers/Admin.h
    Headers/Kitchen.h
    Headers/Manager.h
    Headers/Order.h
    Headers/Users.h
    Headers/Waitstaff.h
    Headers/Tables.h
)

target_include_directories(program PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Headers
)

# For MinGW / GCC compilers
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static -static-libgcc -static-libstdc++")
endif()

# For Visual Studio (MSVC) compiler
if(MSVC)
    set(CompilerFlags
        CMAKE_CXX_FLAGS
        CMAKE_CXX_FLAGS_DEBUG
        CMAKE_CXX_FLAGS_RELEASE
        CMAKE_CXX_FLAGS_MINSIZEREL
        CMAKE_CXX_FLAGS_RELWITHDEBINFO)
    foreach(CompilerFlag ${CompilerFlags})
        string(REPLACE "/MD" "/MT" ${CompilerFlag} "${${CompilerFlag}}")
    endforeach()
endif()
