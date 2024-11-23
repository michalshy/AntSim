//
// Created by Michin on 23.06.2024.
//

#ifndef ANTSIMULATOR_ANTHILL_HPP
#define ANTSIMULATOR_ANTHILL_HPP

#include <memory>
#include <random>
#include "Entities/Ant.hpp"
#include "../Globals.hpp"

namespace{
Random<u32> ant_spawn_generator(0, 360);
}

class Anthill {
    std::vector<Ant> ants;
    std::shared_ptr<sf::Texture> ant_tex;

public:
    Anthill(std::shared_ptr<sf::Texture> _tex);
    std::vector<Ant> GetAnts(){ return ants; }
    void UpdateAnts(sf::Time dt);
};


#endif //ANTSIMULATOR_ANTHILL_HPP
