#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <string>

namespace Ven {

class VenWindow {

 public:
	VenWindow(int w, int h, std::string name);
	~VenWindow();

	VenWindow(const VenWindow &) = delete;
	VenWindow &operator=(const VenWindow &) = delete;

	bool ShouldClose();

 private:

	void InitWindow();

	const int width;
	const int height;

	std::string windowName;
	GLFWwindow *window{};
};

} // Ven
