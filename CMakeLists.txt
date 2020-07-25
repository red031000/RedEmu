cmake_minimum_required(VERSION 3.16)
project(RedEmu LANGUAGES C VERSION 0.1)

set(CMAKE_C_STANDARD 11)

set(SDL2_DIR ${CMAKE_SOURCE_DIR}/cmake)
find_package(SDL2 REQUIRED)

add_executable(RedEmu src/main.c src/GFX/GFX_init.c src/events.c src/exception.c)
target_include_directories(RedEmu PRIVATE include)
target_link_libraries(RedEmu PRIVATE SDL2::SDL2)
target_link_libraries(RedEmu PRIVATE SDL2::SDL2main)

add_custom_command(
        TARGET RedEmu POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_SOURCE_DIR}/bin/SDL2.dll
        ${CMAKE_CURRENT_BINARY_DIR}/SDL2.dll)