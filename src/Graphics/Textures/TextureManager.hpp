//
// Created by Michin on 21.06.2024.
//

#ifndef __TEXTUREMANAGER_HPP__
#define __TEXTUREMANAGER_HPP__

#include <memory>
#include <vector>
#include "SFML/Graphics/Texture.hpp"

class TextureManager {
    std::vector<std::shared_ptr<sf::Texture>> texes;
public:
    TextureManager();
    std::shared_ptr<sf::Texture> getFromId(int id);
};

enum TexCodes
{
    ANT = 0,
    BACKGROUND = 1,
};


#endif //__TEXTUREMANAGER_HPP__
