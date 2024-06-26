//
// Created by Michin on 26.06.2024.
//

#include "Window.hpp"

Window::Window()
{
    window.setFramerateLimit(144);
}

bool Window::SetActive(bool state) {
    return window.setActive(state);
}

void Window::ProcessEvents() {
    for (auto event = sf::Event{}; window.pollEvent(event);)
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
    }
}
