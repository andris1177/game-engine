#pragma once

namespace Engine
{
    namespace Graphics
    {
        class Renderer
        {
        public:
            Renderer(int windowHeight, int windowWidth, const char* windowName)
            : m_WindowWidth(windowWidth), m_WindowHeight(windowHeight), m_windowName(windowName){};
            virtual void init() = 0;

        protected:
            int m_WindowWidth;
            int m_WindowHeight;
            const char* m_windowName;
        };
    }
}