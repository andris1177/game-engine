#pragma once

#include "../header/graphics/vulkan/vulkanRenderer.hpp"

namespace Engine
{
    class App
    {
    public:
        App();
        ~App();
        void run();
        

    private:
        Graphics::VulkanRenderer m_renderer;
    };
}