cmake_minimum_required(VERSION 3.19)
project(cavestory)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -Wextra -pedantic -Werror -DNDEBUG)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")

include(cmake/GTest.cmake)
#include(cmake/boost.cmake)
include(cmake/sdl2.cmake)

find_package(SDL2 REQUIRED)
include_directories (
    ${GTEST_INCLUDE_DIRS}
    ${GMOCK_INCLUDE_DIRS}
    ${SDL2_INCLUDE_DIRS}
    ${SDL2IMAGE_INCLUDE_DIRS}
    src
    test
)

#Tests
file (GLOB TEST_SOURCES "test/*.cpp" )
add_executable(${PROJECT_NAME}-ut  ${TEST_SOURCES})
target_link_libraries(${PROJECT_NAME}-ut gtest gmock gtest_main ${SDL2_LIBRARIES} SDL2main)
enable_testing()
add_test(NAME ${PROJECT_NAME}_test COMMAND ${PROJECT_NAME}-ut)

#Main
file (GLOB SOURCES "src/*.cpp" )
add_executable(${PROJECT_NAME}  ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} SDL2main)
