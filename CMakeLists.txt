cmake_minimum_required(VERSION 3.15)
project(3DShooter)

set(CMAKE_CXX_STANDARD 17)

add_executable(3DShooter Scripts/main.cpp Scripts/framebuffer.cpp Scripts/map.cpp Scripts/textures.cpp Scripts/utils.cpp Scripts/sprite.h Scripts/sprite.cpp)