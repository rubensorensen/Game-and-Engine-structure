#include "window.hpp"

#include <iostream>

static bool g_glfw_initted = false;
static int g_window_count = 0; // Used to determine if GLFW should remain initialized, meaning if all windows are closed, GLFW will be terminated. May not be a perfect solution but it works.

void glfw_error_callback(int error, const char* description)
{
	std::cerr << "GLFW error: " << description << std::endl;
}

Window::Window(const std::string& title, unsigned int width, unsigned int height)
	: title(title), width(width), height(height)
{
	if (!g_glfw_initted) {
		if (!glfwInit()) {
			throw std::runtime_error("Ayo GLFW don't work");
		}

		glfwSetErrorCallback(glfw_error_callback);

		g_glfw_initted = true;
		g_window_count += 1;
	}

	this->glfw_window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
	if (!this->glfw_window) {
		throw std::runtime_error("GLFW window creation failed.");
	}

	g_window_count += 1;
}

Window::~Window()
{
	glfwDestroyWindow(this->glfw_window);
	g_window_count -= 1;
	if (g_window_count <= 0) {
		glfwTerminate();
	}
}

void
Window::update()
{

}