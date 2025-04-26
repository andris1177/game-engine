#pragma once

#include "../window.hpp"

#define GLFW_INCLUDE_VULKAN

namespace Engine
{
    namespace Graphics 
    {
        class VulkanWindow : public Window
        {
            using Window::Window;

        public:
            void init() override;
            void initWindow() override; 
        };
    }
}