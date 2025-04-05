#include "../header/app.hpp"

Engine::App::App()
    : windowWidth(1024), windowHeight(668), windowName("teszt"), window(new Window(windowWidth, windowHeight, windowName)), vulkan(new Vulkan(window->window))
{
}

void Engine::App::run()
{
    while (!window->closeWindow())
    {
        glfwPollEvents();
    }
}

Engine::App::~App()
{
    delete window;
    delete vulkan;
}