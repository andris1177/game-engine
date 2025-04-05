cmake_minimum_required(VERSION 3.30)
project(engine LANGUAGES CXX)

set(GLFW_INCLUDE_DIRS "/usr/include/GLFW")

file(GLOB CPP_SOURCES_1 "src/*.cpp")

add_executable(engine ${CPP_SOURCES_1} main.cpp)

target_include_directories(engine PRIVATE "header")

add_subdirectory(external/glfw)
target_link_libraries(engine glfw)