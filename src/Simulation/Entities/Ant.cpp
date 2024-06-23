//
// Created by Michin on 20.06.2024.
//

#include "Ant.hpp"

Ant::Ant(sf::Texture * tex) {
    ant.setSize(sf::Vector2f(ANT_WIDTH, ANT_HEIGHT));
    ant.setTexture(tex);
    ant.setPosition(960,540); //TODO: REMOVE IN FAVOUR OF POSITION IN ANTHILL
    ant.setOrigin(sf::Vector2f((float(ANT_WIDTH)/2), (float(ANT_HEIGHT)/2)));
}

void Ant::drawAnt(sf::RenderWindow & window) {
    window.draw(ant);
}

void Ant::Behaviour() {
    ant.rotate(1);
    //ant.move(0,0.1);
}
