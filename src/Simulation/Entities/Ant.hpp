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
    float speed = 5.f;
public:
    explicit Ant(sf::Texture* tex);
    void drawAnt(sf::RenderWindow & window);
    void Behaviour();
protected:
    sf::RectangleShape ant;
};


#endif //ANTSIMULATOR_ANT_HPP
