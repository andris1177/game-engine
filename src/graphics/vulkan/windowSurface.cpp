#include "../../../header/graphics/vulkan/vulkanRenderer.hpp"

namespace Engine
{
    namespace Graphics
    {
        void VulkanRenderer::createSurface()
        {
            if (glfwCreateWindowSurface(m_instance, m_window->getWindow(), nullptr, &surface) != VK_SUCCESS) 
            {
                throw std::runtime_error("failed to create window surface!");
            }
        }
    }
}