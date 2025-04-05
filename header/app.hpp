#pragma once
#include "window.hpp"
#include "vulkan.hpp"

namespace Engine
{
    class App
    {
    public:
        App();
        ~App();
        void run();
        

    private:
        const int windowHeight;
        const int windowWidth;
        const std::string windowName;
        Window* window;
        Vulkan* vulkan;
    };
}