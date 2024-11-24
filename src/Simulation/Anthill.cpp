//
// Created by Michin on 23.06.2024.
//

#include "Anthill.hpp"

Anthill::Anthill(std::shared_ptr<sf::Texture> _tex)
{
    for(u8 i = 0U; i < ANTHILL::ANT_NUMBER; i++)
    {
        ants.emplace_back(ant_spawn_generator.Generate(), _tex);
    }
}

void Anthill::UpdateAnts(sf::Time dt) {
    for(Ant& ant: ants)
    {
        ant.Behaviour(dt);
    }
}
