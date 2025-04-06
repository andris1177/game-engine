cmake_minimum_required(VERSION 3.30)
project(engine LANGUAGES CXX)
find_package(Vulkan REQUIRED)

add_subdirectory(external/glfw)

file(GLOB CPP_SOURCES_1 "src/*.cpp")
add_executable(engine ${CPP_SOURCES_1} main.cpp)
target_include_directories(engine PRIVATE "header")
target_link_libraries(engine PRIVATE Vulkan::Vulkan glfw )

#target_compile_options(engine PRIVATE -fsanitize=address -g)
#target_link_options(engine PRIVATE -fsanitize=address)

set(CMAKE_BUILD_TYPE Debug)