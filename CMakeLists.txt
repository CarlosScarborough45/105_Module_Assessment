cmake_minimum_required(VERSION 3.10)
project(VisualApp LANGUAGES CXX)

add_executable(program
    main.cpp
    Users.cpp
)

target_include_directories(program PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Headers
)


