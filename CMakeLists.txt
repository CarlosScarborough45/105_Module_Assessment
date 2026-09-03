cmake_minimum_required(VERSION 3.10)
project(VisualApp LANGUAGES CXX)

add_executable(program
    main.cpp
    Users.cpp
)

target_include_directories(program PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Headers
)

# If using MinGW/GNU toolchain on Windows, prefer static linking to avoid missing
# libgcc/libstdc++ runtime DLLs at execution time.
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static -static-libgcc -static-libstdc++")
endif()


