#include <iostream>

#include "window.hpp"

#include <memory>

int main(void)
{
    std::unique_ptr<Window> window;
    try {
        window = std::make_unique<Window>("Window 1", 1280, 720);
    } catch (std::runtime_error e) {
        std::cerr << "[ERROR] Could not create window: " << e.what() << std::endl;
        return 0;
    }

    while (!window->should_close()) {
        window->update();
        
        poll_events();
    }

	return 0;
}
