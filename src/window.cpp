#include "../header/window.hpp"

Engine::Window::Window(int w, int h, std::string name)
    : windowWidth(w), windowHeight(h), windowName(name)
{   
    initWindow();
}

void Engine::Window::initWindow()
{
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    window = glfwCreateWindow(windowWidth, windowHeight, windowName.c_str(), nullptr, nullptr);

    if (window == nullptr)
    {
        std::cout << "window is missing\n";
    } 
}

bool Engine::Window::closeWindow() const 
{
    return glfwWindowShouldClose(this->window);
}

Engine::Window::~Window()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}