cmake_minimum_required(VERSION 3.4.3)
project(T_Rex_Runner)
SET(PROJECT_NAME t_rex_runner)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake") 

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIR})
include_directories(include)

file(GLOB SOURCES src/*.cpp)

add_executable(t_rex_runner ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY})

