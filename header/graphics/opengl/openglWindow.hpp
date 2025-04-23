#pragma once

#include "../window.hpp"

#define GLFW_INCLUDE_VULKAN

namespace Engine
{
    namespace Graphics 
    {
        class OpenglWindow : private Window
        {
        public:
            OpenglWindow(int width, int height, const char* name)
                : Window(width, height, name) {}
            void init() override;
            void initWindow() override; 
        };
    }
}