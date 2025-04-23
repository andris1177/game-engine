#pragma once

namespace Engine
{
    namespace Graphics
    {
        class Window
        {
        public:
            Window();
            ~Window();

        private:
            int m_windowWidth;
            int m_windowHeight;
            const char* m_windowName;
        };
    }
}