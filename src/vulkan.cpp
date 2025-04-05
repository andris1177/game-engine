#include "../header/vulkan.hpp"

Engine::Vulkan::Vulkan(GLFWwindow* w)
    : window(w)
{
    createInstance();
    listExxesions();
    windowsurface = new WindowSurface(&instance, window);
    windowsurface->createSurface();
    device = new Device(&instance, &windowsurface->surface);
    device->pickPhysicalDevice();
    device->createLogicalDevice();
}

void Engine::Vulkan::createInstance()
{
    // this is thecnically not needed but usefull 
    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Hello Triangle";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    // this part is not optional, it specify the global extensions and validation layers we want to use
    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    // as vulkan can run on multiple os it need an extension to work with a gioven os which glfw can provide
    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions;

    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    createInfo.enabledExtensionCount = glfwExtensionCount;
    createInfo.ppEnabledExtensionNames = glfwExtensions;

    // to enable global validation layer
    createInfo.enabledLayerCount = 0;

    // now create the instance 
    VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);

    if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) 
    {
        std::cout << "failed to create instance!\n";
    }
}

void Engine::Vulkan::listExxesions() const
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

Engine::Vulkan::~Vulkan()
{
    delete device;
    vkDestroyInstance(instance, nullptr);
}