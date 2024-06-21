//
// Created by Michin on 20.06.2024.
//

#include "Ant.hpp"

Ant::Ant(TextureManager& texM) {
    ant.setTexture(texM.getTex(TexCodes::ANT).getTex());
}

void Ant::drawAnt(sf::RenderWindow & window) {
    window.draw(ant);
}
