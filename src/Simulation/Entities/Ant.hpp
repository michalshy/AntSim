//
// Created by Michin on 20.06.2024.
//

#ifndef ANTSIMULATOR_ANT_HPP
#define ANTSIMULATOR_ANT_HPP
#include "SFML/Graphics.hpp"
#include "../../Graphics/Textures/FactoryTexture.hpp"


class Ant {
    sf::Sprite ant;
public:
    Ant(FactoryTexture* fac);
    void drawAnt(sf::RenderWindow & window);
};


#endif //ANTSIMULATOR_ANT_HPP
