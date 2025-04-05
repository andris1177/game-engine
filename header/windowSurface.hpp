#pragma once

#define GLFW_INCLUDE_VULKAN
#include "GLFW/glfw3.h"
#include <iostream>

namespace Engine
{
    class WindowSurface
    {
    public:
        WindowSurface(VkInstance* i, GLFWwindow* w);
        ~WindowSurface();
        void createSurface();
        VkSurfaceKHR surface;    

    private:
        VkInstance* instance;
        GLFWwindow* window;
    };
}