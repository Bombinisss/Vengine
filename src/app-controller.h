#pragma once
#include "ven-window.h"
#include "ven-pipeline.h"

namespace Ven {

	class AppController {
	 public:
		static constexpr int width = 800;
		static constexpr int height = 600;

		void Run();

	 private:
		VenWindow venWindow{ width, height, "Hello Vulkan!"};
		VenPipeline venPipeline{"./shaders/simple_shader.vert.spv", "./shaders/simple_shader.frag.spv"};
	};

} // Ven
