//
// Created by Michin on 20.06.2024.
//

#include <cmath>
#include "Ant.hpp"

Ant::Ant(const u16 rotation, std::shared_ptr<sf::Texture> tex) {
    radar.setPointCount(5);
    radar.setOrigin(ant.getPosition());
    radar.setFillColor(sf::Color(255,255,255,20));
    radar.setPoint(0, sf::Vector2f(ant.getPosition().x-10, ant.getPosition().y));
    radar.setPoint(1, sf::Vector2f(ant.getPosition().x+10, ant.getPosition().y));
    radar.setPoint(2, sf::Vector2f(ant.getPosition().x+20, ant.getPosition().y - 20));
    radar.setPoint(3, sf::Vector2f(ant.getPosition().x, ant.getPosition().y - 30));
    radar.setPoint(4, sf::Vector2f(ant.getPosition().x-20, ant.getPosition().y - 20));
    radar.setRotation(rotation);

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
    window.draw(radar);
}

void Ant::Behaviour(sf::Time dt) {
    ///Count movement
    sf::Vector2f vel;
    vel.x = static_cast<float>(sin((MATH::PI/180)*ant.getRotation()) 
        * ANT::SPEED * dt.asSeconds());
    vel.y = static_cast<float>(-1.f * cos((MATH::PI/180)*ant.getRotation()) 
        * ANT::SPEED * dt.asSeconds());


    ///Check for movement
    if(vel.x != 0 && vel.y != 0)
        ant.move(vel);
        radar.move(vel);
    
    ///Check rotation
    if(turns == 0)
    {
        turns = ant_behaviour_decision.Generate();
        angle = ant_behaviour_rot.Generate();
    }
    if(turns > 0)
    {
        ant.rotate(angle);
        radar.rotate(angle);
        //radar.rotate(angle);
        turns--;
    }

    UpdateRadar();
}

void Ant::UpdateRadar()
{
    
}
