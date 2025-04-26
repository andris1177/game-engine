#pragma once

#include <optional>
#define GLFW_INCLUDE_VULKAN
#include <iostream>
#include <vector>

#include "../renderer.hpp"
#include "vulkanWindow.hpp"

namespace Engine
{
    namespace Graphics
    {
        class VulkanRenderer : public Renderer 
        {
            using Renderer::Renderer;

        public:
            void init() override;
            ~VulkanRenderer();

        private:
            void createInstance();
            void getExtensions() const;
            void createSurface();

        private:
            VulkanWindow* m_window;
            VkInstance m_instance;
            VkSurfaceKHR surface; 
        };
    }
}