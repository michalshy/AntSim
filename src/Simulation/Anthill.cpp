//
// Created by Michin on 23.06.2024.
//

#include "Anthill.hpp"

void Anthill::UpdateAnts() {
    for(Ant& ant: ants)
    {
        ant.Behaviour();
    }
}

Anthill::Anthill(sf::Texture * _antTex) {
    antTex = _antTex;
    for(u8 i = 0U; i < 1U; i++)
    {
        ants.emplace_back(antTex);
    }
}
