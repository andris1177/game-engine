#pragma once

#define GLFW_INCLUDE_VULKAN
#include "GLFW/glfw3.h"
#include <vector>
#include <iostream>
#include <fstream>

namespace Engine
{
    class GraphicsPipeline
    {
    public:
        GraphicsPipeline(VkDevice* d, VkFormat* s, std::vector<VkImageView>* v,  VkExtent2D* e);
        ~GraphicsPipeline();
        void createGraphicsPipeline();
        void createRenderPass();
        void createFramebuffers();
        VkPipeline graphicsPipeline;

    public:
        VkRenderPass renderPass;
        std::vector<VkFramebuffer> swapChainFramebuffers;

    private:
        VkShaderModule createShaderModule(const std::vector<char>& code);

    private:
        VkDevice* device;
        VkFormat* swapChainImageFormat;
        std::vector<VkImageView>* swapChainImageViews;
        VkExtent2D* swapChainExtent;
        std::vector<char> readFile(const std::string& filename);
        VkShaderModule shaderModule;
        VkPipelineLayout pipelineLayout;
    };
}
