cmake_minimum_required(VERSION 3.8)
project(shrub)
add_subdirectory("deps/glfw")
add_library(shrub 
    "src/glad_gl.c"
    "src/shrub_bitmap.cpp"
    "src/shrub_window.cpp"
)
target_include_directories(shrub
    PRIVATE "deps/glfw/include"
    PRIVATE "deps/stb"
    PRIVATE "deps/miniaudio"
    PRIVATE "include"
)
target_link_libraries(shrub PRIVATE glfw)
set_target_properties(shrub PROPERTIES CXX_STANDARD 17)
set_target_properties(shrub PROPERTIES CXX_STANDARD_REQUIRED ON)
set_target_properties(shrub PROPERTIES CXX_EXTENSIONS ON)
