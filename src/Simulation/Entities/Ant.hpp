//
// Created by Michin on 20.06.2024.
//

#ifndef ANTSIMULATOR_ANT_HPP
#define ANTSIMULATOR_ANT_HPP
#include "SFML/Graphics.hpp"
#include "../../Graphics/Textures/TextureManager.hpp"
#include "../../Logic/Timer.hpp"

#define ANT_HEIGHT 20
#define ANT_WIDTH 15

class Ant {
    const float speed = 0.5f;
    double dt;
public:
    explicit Ant(sf::Texture* tex);
    void DrawAnt(sf::RenderWindow & window);
    void Behaviour();
protected:
    sf::RectangleShape ant;
};


#endif //ANTSIMULATOR_ANT_HPP
