#pragma once

#define GLFW_INCLUDE_VULKAN
#include "GLFW/glfw3.h"
#include <iostream>
#include <vector>
#include <optional>
#include <set>

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

    public:
        Device(VkInstance* i, VkSurfaceKHR* s);
        ~Device();
        void pickPhysicalDevice();
        void createLogicalDevice();

    private:
        bool isDeviceSuitable(VkPhysicalDevice device);
        QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

    private:
        VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
        VkInstance* instance;
        QueueFamilyIndices indices;
        VkDevice device;
        VkQueue graphicsQueue;
        VkSurfaceKHR* surface;
        VkQueue presentQueue;
    };
}