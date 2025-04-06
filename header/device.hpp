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

namespace Engine
{
    class Device
    {
    private:
        struct QueueFamilyIndices
        {
            std::optional<uint32_t> graphicsFamily;
            std::optional<uint32_t> presentFamily;

            bool isComplete() 
            {
                return graphicsFamily.has_value() && presentFamily.has_value();
            }
        };

        const std::vector<const char*> deviceExtensions = {
            VK_KHR_SWAPCHAIN_EXTENSION_NAME
        };

        struct SwapChainSupportDetails 
        {
            VkSurfaceCapabilitiesKHR capabilities;
            std::vector<VkSurfaceFormatKHR> formats;
            std::vector<VkPresentModeKHR> presentModes;
        };

    public:
        Device(VkInstance* i, VkSurfaceKHR* s, GLFWwindow* w);
        ~Device();
        void pickPhysicalDevice();
        void createLogicalDevice();
        void createSwapChain();
        void createImageViews();

    public:
        VkDevice device;
        VkFormat swapChainImageFormat;
        

    private:
        bool isDeviceSuitable(VkPhysicalDevice device);
        QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
        bool checkDeviceExtensionSupport(VkPhysicalDevice device);
        SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
        VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
        VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
        VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);

    private:
        VkInstance* instance;
        VkSurfaceKHR* surface;
        GLFWwindow* window;
        VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
        QueueFamilyIndices indices;
        VkQueue graphicsQueue;
        VkQueue presentQueue;
        SwapChainSupportDetails details;
        uint32_t formatCount;
        uint32_t presentModeCount;
        VkSwapchainKHR swapChain;
        std::vector<VkImage> swapChainImages;
        VkExtent2D swapChainExtent;
        std::vector<VkImageView> swapChainImageViews;
    };
}