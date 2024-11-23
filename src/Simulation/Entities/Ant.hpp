//
// Created by Michin on 20.06.2024.
//

#ifndef __ANT_HPP__
#define __ANT_HPP__
#include <memory>
#include "SFML/Graphics.hpp"
#include "../../Graphics/Textures/TextureManager.hpp"
#include "../../Logic/Timer.hpp"
#include "../../Globals.hpp"
#include "../../Common/Random/Random.hpp"

namespace{
Random<float> ant_behaviour_rot(-10.0f,10.0f);
Random<u32> ant_behaviour_decision(0, 100);
}

class Ant {
    const float speed = 100.0f;
    u32 certainity = 80;
public:
    explicit Ant(const u16 rotation, std::shared_ptr<sf::Texture> tex);
    void DrawAnt(sf::RenderWindow & window);
    void Behaviour(sf::Time dt);
protected:
    sf::RectangleShape ant;
};


#endif //__ANT_HPP__
