//
// Created by Michin on 20.06.2024.
//

#include <cmath>
#include "Ant.hpp"

Ant::Ant(const u16 rotation, std::shared_ptr<sf::Texture> tex) {
    certainity = 90;
    turns = 0;
    angle = 0;

    ant.setSize(sf::Vector2f(ANT::WIDTH, ANT::HEIGHT));
    ant.setTexture((sf::Texture*)(tex.get()));
    ant.setPosition(0,0); //TODO: REMOVE IN FAVOUR OF POSITION IN ANTHILL
    ant.setOrigin(sf::Vector2f((float(ANT::WIDTH)/2), (float(ANT::HEIGHT)/2)));
    ant.setRotation(rotation);
}

void Ant::DrawAnt(sf::RenderWindow & window) {
    window.draw(ant);
}

void Ant::Behaviour(sf::Time dt) {
    sf::Vector2f vel;
    vel.x = static_cast<float>(sin((MATH::PI/180)*ant.getRotation()) 
        * ANT::SPEED * dt.asSeconds());
    vel.y = static_cast<float>(-1.f * cos((MATH::PI/180)*ant.getRotation()) 
        * ANT::SPEED * dt.asSeconds());
    if(vel.x != 0 && vel.y != 0)
        ant.move(vel);
    if(turns == 0)
    {
        turns = ant_behaviour_decision.Generate();
        angle = ant_behaviour_rot.Generate();
    }
    if(turns > 0)
    {
        ant.rotate(angle);
        turns--;
    }
}
