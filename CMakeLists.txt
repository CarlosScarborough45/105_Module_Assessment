cmake_minimum_required(VERSION 3.10)

if(NOT DEFINED CMAKE_CXX_COMPILER OR CMAKE_CXX_COMPILER STREQUAL "")
    set(_candidate_compilers
        "C:/Qt/Tools/mingw1310_64/bin/g++.exe"
        "D:/Users/932400098/scoop/apps/gcc/current/bin/g++.exe"
        "C:/Program Files/LLVM/bin/clang++.exe"
        "C:/msys64/ucrt64/bin/g++.exe"
        "C:/msys64/mingw64/bin/g++.exe"
        "C:/mingw64/bin/g++.exe"
        "C:/MinGW/bin/g++.exe"
        "C:/Program Files/Microsoft Visual Studio/2022/Enterprise/VC/Tools/MSVC/14.3*/bin/Hostx64/x64/cl.exe"
        "C:/Program Files/Microsoft Visual Studio/2022/Professional/VC/Tools/MSVC/14.3*/bin/Hostx64/x64/cl.exe"
        "C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/14.3*/bin/Hostx64/x64/cl.exe"
        "C:/Program Files (x86)/Microsoft Visual Studio/2022/BuildTools/VC/Tools/MSVC/14.3*/bin/Hostx64/x64/cl.exe"
    )

    foreach(_compiler IN LISTS _candidate_compilers)
        if(EXISTS "${_compiler}")
            set(CMAKE_CXX_COMPILER "${_compiler}" CACHE FILEPATH "C++ compiler" FORCE)
            break()
        endif()
    endforeach()
endif()

if(NOT DEFINED CMAKE_CXX_COMPILER OR CMAKE_CXX_COMPILER STREQUAL "")
    message(FATAL_ERROR "No C++ compiler found. Install Visual Studio C++ tools, MinGW, or Clang, or pass -DCMAKE_CXX_COMPILER=<path-to-compiler> to CMake.")
endif()

project(VisualApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(105project
    main.cpp
    Admin.cpp
    Kitchen.cpp
    Manager.cpp
    Menu.cpp
    Orders.cpp
    Overides.cpp
    Table.cpp
    Table.Occupancy.cpp
    reports.cpp
    Users.cpp
    Waitstaff.cpp
    Filesystem.cpp
        FileManagement.cpp
        Headers/Filemanagement.h
)

target_include_directories(105project PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/Headers
)

add_custom_command(TARGET 105project POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_CURRENT_SOURCE_DIR}/Data"
        "$<TARGET_FILE_DIR:105project>/Data"
)

# For MinGW / GCC compilers
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static -static-libgcc -static-libstdc++")
endif()

# For Visual Studio (MSVC) compiler
if(MSVC)
    foreach(flag_var
        CMAKE_CXX_FLAGS
        CMAKE_CXX_FLAGS_DEBUG
        CMAKE_CXX_FLAGS_RELEASE
        CMAKE_CXX_FLAGS_MINSIZEREL
        CMAKE_CXX_FLAGS_RELWITHDEBINFO)
        if("${${flag_var}}" MATCHES "/MD")
            string(REPLACE "/MD" "/MT" updated_flag "${${flag_var}}")
            set(${flag_var} "${updated_flag}")
        endif()
    endforeach()
endif()
