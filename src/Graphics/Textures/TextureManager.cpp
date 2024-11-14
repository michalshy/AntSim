//
// Created by Michin on 21.06.2024.
//

#include "TextureManager.hpp"
#include <iostream>

TextureManager::TextureManager() {
    //Ants
    std::shared_ptr<sf::Texture> ant = std::make_shared<sf::Texture>();
    ant->loadFromFile("../src/Graphics/Textures/Images/ant.png");
    texes.push_back(ant);

    //Background
    std::shared_ptr<sf::Texture> background = std::make_shared<sf::Texture>();
    background->loadFromFile("../src/Graphics/Textures/Images/background.png");
    background->setRepeated(true);
    texes.push_back(background);
}

std::shared_ptr<sf::Texture> TextureManager::getFromId(int id) {
    return texes[id];
}


