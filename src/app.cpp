#include "../header/app.hpp"

Engine::App::App()
    : m_renderer(Graphics::VulkanRenderer(1920, 1080, "Engine"))
{
}

void Engine::App::run()
{
    m_renderer.init();
}

Engine::App::~App()
{

}