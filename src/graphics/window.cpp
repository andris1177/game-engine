#include "../../header/graphics/window.hpp"

namespace Engine
{
    namespace Graphics
    {
        Window::Window(int windowWidth, int windowHeight, const char* windowName)
            : m_windowWidth(windowWidth), m_windowHeight(windowHeight), m_windowName(windowName)
        {
            if (!glfwInit())
            {
                std::cout << "Cant initialize glfw\n";
            }
        }

        bool Window::shouldClose()
        {
            return glfwWindowShouldClose(m_window);
        }

        void Window::poolEvents()
        {
            glfwPollEvents();
        }

        GLFWwindow* Window::getWindow()
        {
            return m_window;
        }

        Window::~Window()
        {
            glfwDestroyWindow(m_window);
            glfwTerminate();
        }
    }
}

