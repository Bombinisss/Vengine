#include "app-controller.h"

namespace Ven {

	void AppController::Run() {
		while (!venWindow.ShouldClose()) {
			glfwPollEvents();
		}
	}

} // Ven