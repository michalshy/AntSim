//
// Created by Michin on 20.06.2024.
//

#include "Ant.hpp"

Ant::Ant(FactoryTexture* fac) {
    ant.setTexture(fac->GetFlyweight({"src/Graphics/Textures/Images/ant.png"}).retTex());
}

void Ant::drawAnt(sf::RenderWindow & window) {
    window.draw(ant);
}
