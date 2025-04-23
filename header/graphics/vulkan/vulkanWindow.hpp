#pragma once

#include "../window.hpp"

#define GLFW_INCLUDE_VULKAN

namespace Engine
{
    namespace Graphics 
    {
        class VulkanWindow : private Window
        {
        public:
            VulkanWindow(int width, int height, const char* name)
                : Window(width, height, name) {}
            void init() override;
            void initWindow() override; 
        };
    }
}