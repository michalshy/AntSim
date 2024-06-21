//
// Created by Michin on 20.06.2024.
//

#include "Ant.hpp"

Ant::Ant(sf::Texture * tex) {
    ant.setTexture(*tex);
}

void Ant::drawAnt(sf::RenderWindow & window) {
    window.draw(ant);
}
