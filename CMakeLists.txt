cmake_minimum_required(VERSION 3.10)

project(105_Module_Assessment LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})


# 3. Force CMake to fail if the compiler doesn't support this standard

set(CMAKE_CXX_STANDARD_REQUIRED ON)


include(FetchContent)

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

set(OPENGL_gl_LIBRARY opengl32)
set(USE_EXTERNAL_GLFW OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG 5.0   # or whatever version you want, e.g. 4.5, master
)

FetchContent_Declare(
        raygui
        GIT_REPOSITORY https://github.com/raysan5/raygui.git
        GIT_TAG master
)


FetchContent_MakeAvailable(raylib)
FetchContent_MakeAvailable(raygui)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

add_executable(${PROJECT_NAME}
        Headers/Global.h
        Headers/Screens.h
        Registration.cpp
        Dashboard.cpp
        main.cpp
        Admin_View.cpp
        Staff_View.cpp
        Manager_view.cpp
        Customer_View.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE raylib)
target_include_directories(${PROJECT_NAME} PRIVATE ${raygui_SOURCE_DIR}/src)
target_include_directories(${PROJECT_NAME} PRIVATE
        ${raylib_SOURCE_DIR}/src
        ${raygui_SOURCE_DIR}/src
)