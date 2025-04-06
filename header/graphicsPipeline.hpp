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
        GraphicsPipeline(VkDevice* d, VkFormat* s);
        ~GraphicsPipeline();
        void createGraphicsPipeline();
        void createRenderPass();

    private:
        VkShaderModule createShaderModule(const std::vector<char>& code);

    private:
        VkDevice* device;
        VkFormat* swapChainImageFormat;
        std::vector<char> readFile(const std::string& filename);
        VkShaderModule shaderModule;
        VkRenderPass renderPass;
        VkPipelineLayout pipelineLayout;
        VkPipeline graphicsPipeline;
    };
}
