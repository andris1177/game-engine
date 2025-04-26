#include "../../../header/graphics/vulkan/vulkanRenderer.hpp"

namespace Engine
{
    namespace Graphics
    {
        void VulkanRenderer::init()
        {
            m_window = new VulkanWindow(m_WindowWidth, m_WindowHeight, m_windowName);
            m_window->init();
            m_window->initWindow();
            createInstance();
            getExtensions();
            createSurface();
        }

        void VulkanRenderer::createInstance()
        {
            VkApplicationInfo appInfo{};
            appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO; 
            appInfo.pApplicationName = "engine";
            appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
            appInfo.pEngineName = "No Engine";
            appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
            appInfo.apiVersion = VK_API_VERSION_1_0;

            VkInstanceCreateInfo createInfo{};
            createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
            createInfo.pApplicationInfo = &appInfo;

            uint32_t glfwExtensionCount = 0;
            const char** glfwExtensions;

            glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);
            createInfo.enabledExtensionCount = glfwExtensionCount;
            createInfo.ppEnabledExtensionNames = glfwExtensions;
            createInfo.enabledLayerCount = 0;

            VkResult result = vkCreateInstance(&createInfo, nullptr, &m_instance);

            if (result != VK_SUCCESS)
            {
                std::cerr << "Failed to create the vulkan instance";
            }
        }

        void VulkanRenderer::getExtensions() const 
        {
            uint32_t extensionCount = 0;
            vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
            std::vector<VkExtensionProperties> extensions(extensionCount);
            vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());

            std::cout << "available extensions:\n";

            for (const auto& extension : extensions) 
            {
                std::cout << '\t' << extension.extensionName << '\n';
            }
        }

        VulkanRenderer::~VulkanRenderer()
        {
            vkDestroyInstance(m_instance, nullptr);
            delete m_window;
        }
    }
}



