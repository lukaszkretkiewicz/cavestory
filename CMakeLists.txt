cmake_minimum_required(VERSION 3.16)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

include(FetchContent)
FetchContent_Declare(
SDL2
GIT_REPOSITORY "https://github.com/SDL-mirror/SDL.git"
GIT_TAG release-2.0.10
)
FetchContent_GetProperties(SDL2)
if (NOT sdl2_POPULATED)
    FetchContent_Populate(SDL2)
    add_subdirectory(${sdl2_SOURCE_DIR} ${sdl2_BINARY_DIR})
endif ()

project(CaveStory)


add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(inc)