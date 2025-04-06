#pragma once

#define GLFW_INCLUDE_VULKAN
#include "GLFW/glfw3.h"
#include <iostream>
#include <vector>
#include <optional>
#include <set>
#include <cstdint> 
#include <limits> 
#include <algorithm> 

#include "definitions.hpp"

namespace Engine
{
    class Device
    {
    public:
        Device(VkInstance* i, VkSurfaceKHR* s, GLFWwindow* w);
        ~Device();
        QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
        void pickPhysicalDevice();
        void createLogicalDevice();
        void createSwapChain();
        void createImageViews();

    public:
        VkDevice device;
        VkFormat swapChainImageFormat;
        std::vector<VkImageView> swapChainImageViews;
        VkExtent2D swapChainExtent;
        VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
        QueueFamilyIndices indices;
        VkSwapchainKHR swapChain;
        VkQueue graphicsQueue;
        VkQueue presentQueue;
        

    private:
        bool isDeviceSuitable(VkPhysicalDevice device);
        bool checkDeviceExtensionSupport(VkPhysicalDevice device);
        SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
        VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
        VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
        VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);

    private:
        VkInstance* instance;
        VkSurfaceKHR* surface;
        GLFWwindow* window;
        SwapChainSupportDetails details;
        uint32_t formatCount;
        uint32_t presentModeCount;
        std::vector<VkImage> swapChainImages;
    };
}