#pragma once
//#define GLFW_INCLUDE_VULKAN
#include "GLFW/glfw3.h"
#include <string>
#include <iostream>
#include <stdexcept>

namespace Engine
{
    class Window
    {
    public:
        Window(int w, int h, std::string name);
        ~Window();
        bool closeWindow() const;

    private:
        int windowWidth;
        int windowHeight;
        std::string windowName;
        void initWindow();
        GLFWwindow *window;
    };
}