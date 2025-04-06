#include "../header/app.hpp"

Engine::App::App()
    : windowWidth(1920), windowHeight(1080), windowName("teszt"), window(new Window(windowWidth, windowHeight, windowName)), vulkan(new Vulkan(window->window))
{
}

void Engine::App::run()
{
    while (!window->closeWindow())
    {
        glfwPollEvents();
        vulkan->drawFrame();
    }

    vkDeviceWaitIdle(vulkan->device->device);
}

Engine::App::~App()
{
    delete window;
    delete vulkan;
}