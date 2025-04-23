#include "../../../header/graphics/opengl/openglWindow.hpp"

void Engine::Graphics::OpenglWindow::init()
{
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void Engine::Graphics::OpenglWindow::initWindow()
{
    window = glfwCreateWindow(m_windowWidth, m_windowHeight, m_windowName, nullptr, nullptr);
    std::cout << "opengl window has been created" << std::endl;
}