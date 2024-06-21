//
// Created by Michin on 20.06.2024.
//

#ifndef ANTSIMULATOR_ANT_HPP
#define ANTSIMULATOR_ANT_HPP
#include "SFML/Graphics.hpp"
#include "../../Graphics/Textures/AntTexture.hpp"

class Ant {
    AntTexture tex = AntTexture();
    sf::Sprite ant;
public:
    Ant();
    void drawAnt(sf::RenderWindow * window);
};


#endif //ANTSIMULATOR_ANT_HPP
