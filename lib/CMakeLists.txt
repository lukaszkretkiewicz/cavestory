cmake_minimum_required(VERSION 3.10)

add_library(${PROJECT_NAME}_lib 
            example.cpp)
target_compile_options(${PROJECT_NAME}_lib PRIVATE -Wall -Wextra -pedantic -Wconversion -Werror)
target_include_directories(${PROJECT_NAME}_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})