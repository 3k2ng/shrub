cmake_minimum_required(VERSION 3.15)
project(shrub)
add_subdirectory("deps/glfw")
add_library(shrub 
    "src/glad/gl.c"
    "src/shrub/context.cpp"
    "src/shrub/bitmap.cpp"
    "src/shrub/window.cpp"
)
target_include_directories(shrub
    PRIVATE "deps/glfw/include"
    PRIVATE "deps/stb"
    PRIVATE "include"
)
target_link_libraries(shrub PRIVATE glfw)
