#include "../header/app.hpp"

Engine::App::App()
    : windowWidth(1024), windowHeight(668), windowName("teszt"), window(Window(windowWidth, windowHeight, windowName))
{

}

void Engine::App::run()
{
    while (!window.closeWindow())
    {
        glfwPollEvents();
    }
}