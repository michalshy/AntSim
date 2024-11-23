//
// Created by Michin on 23.06.2024.
//

#include "Anthill.hpp"

void Anthill::UpdateAnts(u32 dt) {
    for(Ant& ant: ants)
    {
        ant.Behaviour(dt);
    }
}

Anthill::Anthill(std::shared_ptr<sf::Texture> _tex)
{
    antTex = _tex;
    // Development purposes adding 1 ant for now
    for(u8 i = 0U; i < 1U; i++)
    {
        ants.emplace_back(antTex);
    }
}