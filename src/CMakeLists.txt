cmake_minimum_required(VERSION 3.10)

add_executable(${PROJECT_NAME}
                main.cpp
                Game.cpp
                IGame.cpp)
#add_library(${PROJECT_NAME}_src)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -Wconversion -Werror)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME} PUBLIC ${PROJECT_NAME}_headers ${SDL2_LIBRARIES} SDL2main SDL2-static m)
#target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}_src)
# target_link_libraries(${PROJECT_NAME} PUBLIC ${SDL2_LIBRARIES} SDL2main SDL2-static m)
