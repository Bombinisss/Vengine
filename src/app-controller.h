#pragma once
#include "ven-window.h"

namespace Ven {

	class AppController {
	 public:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;

		void Run();

	 private:
		VenWindow venWindow{WIDTH, HEIGHT, "Hello Vulkan!"};
	};

} // Ven
