cmake_minimum_required(VERSION 3.30)
project(engine LANGUAGES CXX)

find_package(Vulkan REQUIRED)
set(GLFW_INCLUDE_DIRS "/usr/include/GLFW")
find_package(glm REQUIRED)

file(GLOB CPP_SOURCES_1 "src/*.cpp")

add_executable(engine ${CPP_SOURCES_1} main.cpp)

target_include_directories(engine PRIVATE "header")

target_link_libraries(engine PRIVATE Vulkan::Vulkan glfw glm)