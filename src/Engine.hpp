//
// Created by Michin on 21.06.2024.
//

#ifndef ANTSIMULATOR_ENGINE_HPP
#define ANTSIMULATOR_ENGINE_HPP

#include "Graphics/MainWindow.hpp"
#include "Simulation/Entities/Ant.hpp"

class Engine {
    MainWindow window = MainWindow();
    std::vector<Ant> ants;

public:
    Engine();
    void Loop();
};


#endif //ANTSIMULATOR_ENGINE_HPP
