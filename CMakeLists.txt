cmake_minimum_required(VERSION 3.10)
project(game-engine VERSION 0.1)
project(LANGUAGE CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Debug)

find_package(Vulkan REQUIRED)
add_subdirectory(external/glfw)

file(GLOB_RECURSE src CONFIGURE_DEPENDS "src/*.cpp")

add_executable(engine ${src} main.cpp)

target_link_libraries(engine PUBLIC glfw Vulkan::Vulkan)