//
// Created by Michin on 23.06.2024.
//

#ifndef ANTSIMULATOR_ANTHILL_HPP
#define ANTSIMULATOR_ANTHILL_HPP

#include <memory>
#include "Entities/Ant.hpp"
#include "../Globals.hpp"

class Anthill {
    std::vector<Ant> ants;
    std::shared_ptr<sf::Texture> antTex;
public:
    Anthill(std::shared_ptr<sf::Texture> _tex);
    std::vector<Ant> GetAnts(){ return ants; }
    void UpdateAnts(u32 dt);
};


#endif //ANTSIMULATOR_ANTHILL_HPP
