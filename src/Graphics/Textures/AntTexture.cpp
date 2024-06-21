//
// Created by Michin on 21.06.2024.
//

#include "AntTexture.hpp"

AntTexture::AntTexture() {
    if(!texture.loadFromFile("src/Graphics/Textures/Images/ant.png", sf::IntRect(10,10,32,32)))
    {
        //TODO: ERROR HANDLING
    }
}
