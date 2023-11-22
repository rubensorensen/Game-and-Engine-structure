#include "window.hpp"

#include <iostream>

static bool g_glfw_initted = false;
static int g_window_count = 0; // Used to determine if GLFW should remain initialized, meaning if all windows are closed, GLFW will be terminated. May not be a perfect solution but it works.

void
glfw_error_callback(int error, const char* description)
{
	std::cerr << "[ERROR] GLFW error: " << description << std::endl;
}

static void
init_glfw()
{    
    if (!glfwInit()) {
        throw std::runtime_error("GLFW could not be initialized");
    }

    glfwSetErrorCallback(glfw_error_callback);

    g_glfw_initted = true;
    g_window_count += 1;
}

Window::Window(const std::string& title, unsigned int width, unsigned int height)
	: title(title), width(width), height(height)
{
	if (!g_glfw_initted) {
        init_glfw();
	}

	this->glfw_window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
	if (!this->glfw_window) {
		throw std::runtime_error("GLFW failed to create window.");
	}

	g_window_count += 1;

    std::cout << "[INFO] Window created!" << std::endl;
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
