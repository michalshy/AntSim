//
// Created by Michin on 21.06.2024.
//

#ifndef ANTSIMULATOR_ANTTEXTURE_HPP
#define ANTSIMULATOR_ANTTEXTURE_HPP
#include "SFML/Graphics.hpp"

class AntTexture {
    sf::Texture texture;
public:
    AntTexture();
    sf::Texture getTex(){ return texture; }
};


#endif //ANTSIMULATOR_ANTTEXTURE_HPP
