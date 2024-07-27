//
// Created by Michin on 21.06.2024.
//

#include "TextureManager.hpp"
#include <iostream>

TextureManager::TextureManager() {
    //Ants
    auto* ant = new sf::Texture;
    ant->loadFromFile("../src/Graphics/Textures/Images/ant.png");
    texes.push_back(ant);

    //Background
    auto* background = new sf::Texture;
    background->loadFromFile("../src/Graphics/Textures/Images/background.png");
    background->setRepeated(true);
    texes.push_back(background);
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

