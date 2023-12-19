cmake_minimum_required (VERSION 3.1)

project (main)

set(CMAKE_CXX_FLAGS "-std=c++17")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(GLUT REQUIRED)
find_package(SDL REQUIRED)

# ImGui library
add_library(imgui
    external/imgui/imgui.cpp
    external/imgui/imgui_draw.cpp
    external/imgui/imgui_widgets.cpp
    external/imgui/imgui_tables.cpp
    # Add other imgui files if needed
)
target_include_directories(imgui PUBLIC external/imgui)



file(GLOB SOURCES ./includes/*.h *.cpp ./src/*.cpp)

add_executable(main ${SOURCES})

target_link_libraries(main PRIVATE imgui)
