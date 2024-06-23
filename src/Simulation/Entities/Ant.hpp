//
// Created by Michin on 20.06.2024.
//

#ifndef ANTSIMULATOR_ANT_HPP
#define ANTSIMULATOR_ANT_HPP
#include "SFML/Graphics.hpp"
#include "../../Graphics/Textures/TextureManager.hpp"

#define ANT_HEIGHT 200
#define ANT_WIDTH 150

class Ant {
    sf::RectangleShape ant;
public:
    explicit Ant(sf::Texture* tex);
    void drawAnt(sf::RenderWindow & window);
    void Behaviour();
};


#endif //ANTSIMULATOR_ANT_HPP
