//
// Created by Michin on 21.06.2024.
//

#ifndef ANTSIMULATOR_TEXTUREMANAGER_HPP
#define ANTSIMULATOR_TEXTUREMANAGER_HPP


#include <vector>
#include "SFML/Graphics/Texture.hpp"

class TextureManager {
    std::vector<sf::Texture*> texes;
public:
    TextureManager();
    sf::Texture* getFromId(int id);
    ~TextureManager();
};

enum TexCodes
{
    ANT = 0,
};


#endif //ANTSIMULATOR_TEXTUREMANAGER_HPP
