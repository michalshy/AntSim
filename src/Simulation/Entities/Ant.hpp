//
// Created by Michin on 20.06.2024.
//

#ifndef ANTSIMULATOR_ANT_HPP
#define ANTSIMULATOR_ANT_HPP
#include <memory>
#include "SFML/Graphics.hpp"
#include "../../Graphics/Textures/TextureManager.hpp"
#include "../../Logic/Timer.hpp"
#include "../../Globals.hpp"

class Ant {
    const float speed = 100.0f;
public:
    explicit Ant(std::shared_ptr<sf::Texture> tex);
    void DrawAnt(sf::RenderWindow & window);
    void Behaviour(sf::Time dt);
protected:
    sf::RectangleShape ant;
};


#endif //ANTSIMULATOR_ANT_HPP
