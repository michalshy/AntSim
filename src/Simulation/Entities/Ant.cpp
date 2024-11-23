//
// Created by Michin on 20.06.2024.
//

#include <cmath>
#include "Ant.hpp"

Ant::Ant(std::shared_ptr<sf::Texture> tex) {
    printf("ant%x\n", tex);
    ant.setSize(sf::Vector2f(AntConsts::WIDTH, AntConsts::HEIGHT));
    ant.setTexture((sf::Texture*)(tex.get()));
    ant.setPosition(0,0); //TODO: REMOVE IN FAVOUR OF POSITION IN ANTHILL
    ant.setOrigin(sf::Vector2f((float(AntConsts::WIDTH)/2), (float(AntConsts::HEIGHT)/2)));
}

void Ant::DrawAnt(sf::RenderWindow & window) {
    window.draw(ant);
}

void Ant::Behaviour(u32 dt) {
    sf::Vector2f vel;
    vel.x = static_cast<float>(sin((MathConsts::PI/180)*ant.getRotation()) * speed * dt);
    vel.y = static_cast<float>(-1.f * cos((MathConsts::PI/180)*ant.getRotation()) * speed * dt);
    ant.move(vel);
    ant.rotate(static_cast<float>(-0.2 * dt));
}
