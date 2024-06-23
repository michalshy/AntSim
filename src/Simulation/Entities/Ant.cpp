//
// Created by Michin on 20.06.2024.
//

#include "Ant.hpp"

Ant::Ant(sf::Texture * tex) {
    ant.setScale(0.1,0.1);
    ant.setTexture(*tex);
    ant.setPosition(1000,500);
}

void Ant::drawAnt(sf::RenderWindow & window) {
    window.draw(ant);
}

void Ant::Behaviour() {
    ant.rotate(1);
    ant.move(0.1,0.1);
}
