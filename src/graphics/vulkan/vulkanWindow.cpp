#include "../../../header/graphics/vulkan/vulkanWindow.hpp"

void Engine::Graphics::VulkanWindow::init()
{
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
}

void Engine::Graphics::VulkanWindow::initWindow()
{
    m_window = glfwCreateWindow(m_windowWidth, m_windowHeight, m_windowName, nullptr, nullptr);
    std::cout << "vulkan window has been created" << std::endl;
}