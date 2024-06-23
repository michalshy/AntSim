//
// Created by Michin on 23.06.2024.
//

#ifndef ANTSIMULATOR_ANTHILL_HPP
#define ANTSIMULATOR_ANTHILL_HPP

#include "Entities/Ant.hpp"

class Anthill {
    std::vector<Ant> ants;
    sf::Texture * antTex = nullptr;
public:
    explicit Anthill(sf::Texture * _antTex);
    void UpdateAnts();
    std::vector<Ant> GetAnts(){ return ants; }
};


#endif //ANTSIMULATOR_ANTHILL_HPP
