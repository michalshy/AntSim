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
    ants.emplace_back(antTex);
}
