cmake_minimum_required(VERSION 3.16)
project(RedEmu LANGUAGES C VERSION 0.1)

set(CMAKE_C_STANDARD 11)

add_executable(RedEmu src/main.c)
target_include_directories(RedEmu PRIVATE include)