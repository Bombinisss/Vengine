#pragma once

#include <string>
#include <vector>
namespace Ven {

	class VenPipeline {
	 public:
		VenPipeline(const std::string& vertFilepath, const std::string& fragFilepath);

	 private:
		static std::vector<char> ReadFile(const std::string& filepath);

		void CreateGraphicsPipeline(const std::string& vertFilepath, const std::string& fragFilepath);
	};

} // Ven
