//
// Created by Michin on 26.06.2024.
//

#ifndef ANTSIMULATOR_WINDOW_HPP
#define ANTSIMULATOR_WINDOW_HPP
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

class Window {
    sf::RenderWindow window = sf::RenderWindow{ { 1920u, 1080u }, "AntSimulator" };
public:
    Window();
    sf::RenderWindow &GetWindow(){ return window; }
    bool SetActive(bool state);
    bool IsOpen(){ return window.isOpen(); }
    void ProcessEvents();
};


#endif //ANTSIMULATOR_WINDOW_HPP
