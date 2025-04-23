#include "../../header/graphics/window.hpp"

Engine::Graphics::Window::Window(int windowWidth, int windowHeight, const char* windowName)
    : m_windowWidth(windowWidth), m_windowHeight(windowHeight), m_windowName(windowName)
{
    if (!glfwInit())
    {
        std::cout << "Cant initialize glfw\n";
    }
}

bool Engine::Graphics::Window::shouldClose()
{
    return glfwWindowShouldClose(window);
}

void Engine::Graphics::Window::poolEvents()
{
    glfwPollEvents();
}

Engine::Graphics::Window::~Window()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}