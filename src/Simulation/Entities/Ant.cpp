//
// Created by Michin on 20.06.2024.
//

#include <cmath>
#include "Ant.hpp"

#define PI 3.14

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
    sf::Vector2f vel;
    vel.x = sin((PI/180)*ant.getRotation()) * speed;
    vel.y = -1.f * cos((PI/180)*ant.getRotation()) * speed;

    ant.move(vel);
    ant.rotate(-1);

}
