cmake_minimum_required(VERSION 3.10)

project(CaveStory)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

#####   SDL   ####
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

include_directories(src)

add_subdirectory(src)
add_subdirectory(tst)
add_subdirectory(lib)