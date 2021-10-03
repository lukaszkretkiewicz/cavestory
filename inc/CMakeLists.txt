cmake_minimum_required(VERSION 3.10)
set(HEADERS
    Game.hpp
    IGame.hpp
    IGraphicsBuilder.hpp
    GraphicsBuilderAdapter.hpp)

add_library(${PROJECT_NAME}_headers ${HEADERS})
target_include_directories(${PROJECT_NAME}_headers PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
set_target_properties(${PROJECT_NAME}_headers PROPERTIES LINKER_LANGUAGE CXX)