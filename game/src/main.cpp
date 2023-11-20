#include <iostream>

#include "window.hpp"

int main(void)
{
	Window window("Window 1", 1280, 720);

	while (!window.should_close()) {
		window.update();

		poll_events();
	}

	return 0;
}
