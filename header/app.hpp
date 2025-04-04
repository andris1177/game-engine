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
        int windowHeight;
        int windowWidth;
        std::string windowName;
        Window window;
    };
}