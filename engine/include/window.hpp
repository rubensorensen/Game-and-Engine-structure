#pragma once

#include "core.hpp"

#include <GLFW/glfw3.h>

#include <string>

class ENGINE_API Window
{
public:
	Window(const std::string& title, unsigned int width, unsigned int height);
	~Window();

	inline bool should_close() { return glfwWindowShouldClose(this->glfw_window); }

	void update();

private:
	std::string title;
	unsigned int width, height;

	GLFWwindow* glfw_window;
};