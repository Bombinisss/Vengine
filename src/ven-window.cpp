#include "ven-window.h"

#include <stdexcept>

namespace Ven
{

	VenWindow::VenWindow(int w, int h, std::string name) : width{w}, height{h}, windowName{std::move(name)} {
		InitWindow();
	}
	VenWindow::~VenWindow() {
		glfwDestroyWindow(window);
		glfwTerminate();
	}
	void VenWindow::InitWindow() {
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
	}
	bool VenWindow::ShouldClose() {
		return glfwWindowShouldClose(window);
	}
	void VenWindow::CreateWindowSurface(VkInstance instance, VkSurfaceKHR* surface) {
		if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS) {
			throw std::runtime_error("failed to create window surface");
		}
	}
} // Ven