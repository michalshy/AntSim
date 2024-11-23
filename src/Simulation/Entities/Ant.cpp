//
// Created by Michin on 20.06.2024.
//

#include <cmath>
#include "Ant.hpp"

Ant::Ant(const u16 rotation, std::shared_ptr<sf::Texture> tex) {
    ant.setSize(sf::Vector2f(AntConsts::WIDTH, AntConsts::HEIGHT));
    ant.setTexture((sf::Texture*)(tex.get()));
    ant.setPosition(0,0); //TODO: REMOVE IN FAVOUR OF POSITION IN ANTHILL
    ant.setOrigin(sf::Vector2f((float(AntConsts::WIDTH)/2), (float(AntConsts::HEIGHT)/2)));
    ant.setRotation(rotation);
}

void Ant::DrawAnt(sf::RenderWindow & window) {
    window.draw(ant);
}

void Ant::Behaviour(sf::Time dt) {
    sf::Vector2f vel;
    vel.x = static_cast<float>(sin((MathConsts::PI/180)*ant.getRotation()) * speed * dt.asSeconds());
    vel.y = static_cast<float>(-1.f * cos((MathConsts::PI/180)*ant.getRotation()) * speed * dt.asSeconds());
    if(vel.x != 0 && vel.y != 0)
        ant.move(vel);
    if(ant_behaviour_decision.Generate() > certainity)
        ant.rotate((float)ant_behaviour_rot.Generate());
}
