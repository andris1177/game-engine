#pragma once

#define GLFW_INCLUDE_VULKAN
#include "GLFW/glfw3.h"
#include <iostream>
#include <vector>

#include "device.hpp"
#include "windowSurface.hpp"
#include "graphicsPipeline.hpp"
#include "commandbuffer.hpp"

namespace Engine
{
    class Vulkan
    {
    public:
        Vulkan(GLFWwindow* w);
        ~Vulkan();
        void drawFrame();

    public:
        Device* device;

    private:
        void createInstance();
        void listExxesions() const;
        void createSyncObjects();

    private:
        GLFWwindow* window; 
        VkInstance instance;
        WindowSurface* windowsurface;
        GraphicsPipeline* graphicspipeline;
        CommandBuffer* commandbuffer;
        VkSemaphore imageAvailableSemaphore;
        VkSemaphore renderFinishedSemaphore;
        VkFence inFlightFence;
    };
}
