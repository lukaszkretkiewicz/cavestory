cmake_minimum_required(VERSION 3.10)

include(GoogleTest)

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)


add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

set(MOCK
    GraphicsBuilderMock.cpp)

add_library(${PROJECT_NAME}_mocks ${MOCK})
add_executable(${PROJECT_NAME}-test main.cpp)
target_include_directories(${PROJECT_NAME}_mocks PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME}-test
                      ${PROJECT_NAME}_lib
                      ${PROJECT_NAME}_headers
                      ${PROJECT_NAME}_mocks 
                      gtest
                      gtest_main 
                      gmock
                      gmock_main)

gtest_discover_tests(${PROJECT_NAME}-test)