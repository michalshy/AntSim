//
// Created by Michin on 20.06.2024.
//

#include <cmath>
#include "Ant.hpp"


#define PI 3.14

Ant::Ant(sf::Texture * tex) {
    dt = Timer::GetDt();
    ant.setSize(sf::Vector2f(ANT_WIDTH, ANT_HEIGHT));
    ant.setTexture(tex);
    ant.setPosition(960,540); //TODO: REMOVE IN FAVOUR OF POSITION IN ANTHILL
    ant.setOrigin(sf::Vector2f((float(ANT_WIDTH)/2), (float(ANT_HEIGHT)/2)));
}

void Ant::drawAnt(sf::RenderWindow & window) {
    window.draw(ant);
}

void Ant::Behaviour() {
    dt = Timer::GetDt();
    sf::Vector2f vel;
    vel.x = sin((PI/180)*ant.getRotation()) * speed * dt;
    vel.y = -1.f * cos((PI/180)*ant.getRotation()) * speed * dt;

    ant.move(vel);
    ant.rotate(-1);

}
