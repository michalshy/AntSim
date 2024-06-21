//
// Created by Michin on 21.06.2024.
//

#ifndef ANTSIMULATOR_MYTEX_HPP
#define ANTSIMULATOR_MYTEX_HPP

#include "SFML/Graphics.hpp"

class MyTex
{
    sf::Texture texture;
public:
    sf::Texture getTex(){ return texture; }
};

#endif //ANTSIMULATOR_MYTEX_HPP
