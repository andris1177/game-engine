#pragma once

#include <iostream>
#include "GLFW/glfw3.h"

namespace Engine
{
    namespace Graphics
    {
        class Window
        {
        public:
            Window(int windowWidth, int windowHeight, const char* windowName);
            ~Window();
            virtual void init() = 0;
            virtual void initWindow() = 0;
            bool shouldClose();
            void poolEvents();

        protected:
            int m_windowWidth;
            int m_windowHeight;
            const char* m_windowName;
            GLFWwindow* window;
        };
    }
}