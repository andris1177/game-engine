#pragma once
#define GLFW_INCLUDE_VULKAN
#include "GLFW/glfw3.h"
#include <iostream>

#include "definitions.hpp"
#include "device.hpp"

namespace Engine
{
    class CommandBuffer
    {
    public:
        CommandBuffer(Device* d, VkRenderPass* r, std::vector<VkFramebuffer>* s, VkExtent2D* swa, VkPipeline* g);
        ~CommandBuffer();
        void createCommandPool();
        void createCommandBuffer();
        void recordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);

    public:
        VkCommandBuffer commandBuffer;

    private:
        Device* device;
        VkRenderPass* renderPass;
        std::vector<VkFramebuffer>* swapChainFramebuffers;
        VkExtent2D* swapChainExtent;
        VkPipeline* graphicsPipeline;
        VkCommandPool commandPool;
    };
}