#pragma once

#define GLFW_INCLUDE_VULKAN
#include "GLFW/glfw3.h"
#include <iostream>
#include <vector>

#include "device.hpp"
#include "windowSurface.hpp"

namespace Engine
{
    class Vulkan
    {
    public:
        Vulkan(GLFWwindow* w);
        ~Vulkan();

    private:
        void createInstance();
        void listExxesions() const;

    private:
        VkInstance instance;
        Device* device;
        WindowSurface* windowsurface;
        GLFWwindow* window;
    };
}
