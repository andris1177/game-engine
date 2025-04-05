#pragma once
#include "window.hpp"

namespace Engine
{
    class App
    {
    public:
        App();
        void run();
        

    private:
        const int windowHeight;
        const int windowWidth;
        std::string windowName;
        Window window;
    };
}