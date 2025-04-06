#include "../header/windowSurface.hpp"

Engine::WindowSurface::WindowSurface(VkInstance* i, GLFWwindow* w)
    : instance(i), window(w)
{

}

void Engine::WindowSurface::createSurface()
{
    if (glfwCreateWindowSurface(*(instance), window, nullptr, &surface) != VK_SUCCESS) 
    {
        throw std::runtime_error("failed to create window surface!");
    }
}

Engine::WindowSurface::~WindowSurface()
{
    vkDestroySurfaceKHR(*(instance), surface, nullptr);
}