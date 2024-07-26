//
// Created by Michin on 21.06.2024.
//

#include "TextureManager.hpp"

TextureManager::TextureManager() {
    auto* ant = new sf::Texture;
    ant->loadFromFile("../src/Graphics/Textures/Images/ant.png");
    texes.push_back(ant);
}

sf::Texture *TextureManager::getFromId(int id) {
    return texes[id];
}

TextureManager::~TextureManager() {
    for(auto tex : texes)
    {
        delete tex;
    }
}

