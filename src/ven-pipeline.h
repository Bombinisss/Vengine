#pragma once

#include "ven_device.h"

#include <string>
#include <vector>
namespace Ven {

	struct PipelineConfigInfo {};
	class VenPipeline {
	 public:
		VenPipeline(VenDevice& device, const std::string& vertFilepath, const std::string& fragFilepath, const PipelineConfigInfo& configInfo);
		~VenPipeline() {}

		VenPipeline(const VenPipeline&) = delete;
		void operator=(const VenPipeline&) = delete;

		static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width, uint32_t height);

	 private:
		static std::vector<char> ReadFile(const std::string& filepath);

		void CreateGraphicsPipeline(const std::string& vertFilepath, const std::string& fragFilepath, const PipelineConfigInfo& configInfo);

		void CreateShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule);

		VenDevice& venDevice;
		VkPipeline graphicsPipeline;
		VkShaderModule vertShaderModule;
		VkShaderModule fragShaderModule;
	};

} // Ven
