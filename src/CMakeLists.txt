cmake_minimum_required(VERSION 3.10)

add_executable(${PROJECT_NAME} main.cpp)
add_library(${PROJECT_NAME}_src
            Game.cpp
            IGame.cpp)
target_compile_options(${PROJECT_NAME}_src PRIVATE -Wall -Wextra -pedantic -Wconversion -Werror)
target_include_directories(${PROJECT_NAME}_src PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}_headers)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}_src)
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} SDL2main SDL2-static m)