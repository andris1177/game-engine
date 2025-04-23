#include "../header/app.hpp"

Engine::App::App()
{
    Graphics::VulkanWindow window(1920, 1080, "teszt");
    window.init();
    window.initWindow();
}

void Engine::App::run()
{
    
}

Engine::App::~App()
{

}