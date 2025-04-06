#include "../header/vulkan.hpp"

Engine::Vulkan::Vulkan(GLFWwindow* w)
    : window(w)
{
    createInstance();
    listExxesions();
    windowsurface = new WindowSurface(&instance, window);
    windowsurface->createSurface();
    device = new Device(&instance, &windowsurface->surface, window);
    device->pickPhysicalDevice();
    device->createLogicalDevice();
    device->createSwapChain();
    device->createImageViews();
    graphicspipeline = new GraphicsPipeline(&device->device, &device->swapChainImageFormat, &device->swapChainImageViews, &device->swapChainExtent);
    graphicspipeline->createRenderPass();
    graphicspipeline->createGraphicsPipeline();
    graphicspipeline->createFramebuffers();
    commandbuffer = new CommandBuffer(device, &graphicspipeline->renderPass, &graphicspipeline->swapChainFramebuffers, &device->swapChainExtent, &graphicspipeline->graphicsPipeline);
    commandbuffer->createCommandPool();
    commandbuffer->createCommandBuffer();
    createSyncObjects();

}

void Engine::Vulkan::createInstance()
{
    // this is thecnically not needed but usefull 
    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Engine";
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

void  Engine::Vulkan::drawFrame()
{
    vkWaitForFences(device->device, 1, &inFlightFence, VK_TRUE, UINT64_MAX);
    vkResetFences(device->device, 1, &inFlightFence);

    uint32_t imageIndex;
    vkAcquireNextImageKHR(device->device, device->swapChain, UINT64_MAX, imageAvailableSemaphore, VK_NULL_HANDLE, &imageIndex);

    vkResetCommandBuffer(commandbuffer->commandBuffer, 0);
    commandbuffer->recordCommandBuffer(commandbuffer->commandBuffer, imageIndex);

    VkSubmitInfo submitInfo{};
    submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;

    VkSemaphore waitSemaphores[] = {imageAvailableSemaphore};
    VkPipelineStageFlags waitStages[] = {VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT};
    submitInfo.waitSemaphoreCount = 1;
    submitInfo.pWaitSemaphores = waitSemaphores;
    submitInfo.pWaitDstStageMask = waitStages;

    submitInfo.commandBufferCount = 1;
    submitInfo.pCommandBuffers = &commandbuffer->commandBuffer;

    VkSemaphore signalSemaphores[] = {renderFinishedSemaphore};
    submitInfo.signalSemaphoreCount = 1;
    submitInfo.pSignalSemaphores = signalSemaphores;

    if (vkQueueSubmit(device->graphicsQueue, 1, &submitInfo, inFlightFence) != VK_SUCCESS) 
    {
        throw std::runtime_error("failed to submit draw command buffer!");
    }

    VkPresentInfoKHR presentInfo{};
    presentInfo.sType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;

    presentInfo.waitSemaphoreCount = 1;
    presentInfo.pWaitSemaphores = signalSemaphores;

    VkSwapchainKHR swapChains[] = {device->swapChain};
    presentInfo.swapchainCount = 1;
    presentInfo.pSwapchains = swapChains;
    presentInfo.pImageIndices = &imageIndex;

    vkQueuePresentKHR(device->presentQueue, &presentInfo);
}

void Engine::Vulkan::createSyncObjects()
{
    VkSemaphoreCreateInfo semaphoreInfo{};
    semaphoreInfo.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;

    VkFenceCreateInfo fenceInfo{};
    fenceInfo.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
    fenceInfo.flags = VK_FENCE_CREATE_SIGNALED_BIT;

    if (vkCreateSemaphore(device->device, &semaphoreInfo, nullptr, &imageAvailableSemaphore) != VK_SUCCESS ||
    vkCreateSemaphore(device->device, &semaphoreInfo, nullptr, &renderFinishedSemaphore) != VK_SUCCESS ||
    vkCreateFence(device->device, &fenceInfo, nullptr, &inFlightFence) != VK_SUCCESS) 
    {
        throw std::runtime_error("failed to create semaphores!");
    }
}

Engine::Vulkan::~Vulkan()
{
    vkDestroySemaphore(device->device, imageAvailableSemaphore, nullptr);
    vkDestroySemaphore(device->device, renderFinishedSemaphore, nullptr);
    vkDestroyFence(device->device, inFlightFence, nullptr);
    delete commandbuffer;
    delete graphicspipeline;
    delete device;
    delete windowsurface;
    vkDestroyInstance(instance, nullptr);
}