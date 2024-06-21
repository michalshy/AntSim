//
// Created by Michin on 20.06.2024.
//

#include "Ant.hpp"

Ant::Ant() {
    ant.setTexture(tex.getTex());
}

void Ant::drawAnt(sf::RenderWindow *window) {
    window->draw(ant);
}
