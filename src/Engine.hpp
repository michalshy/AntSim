//
// Created by Michin on 21.06.2024.
//

#ifndef ANTSIMULATOR_ENGINE_HPP
#define ANTSIMULATOR_ENGINE_HPP

#include "Graphics/MainWindow.hpp"
#include "Graphics/Textures/TextureManager.hpp"
#include "Simulation/Anthill.hpp"

class Engine {
    TextureManager * tM;
    MainWindow * window;
    Anthill * ants;
public:
    Engine();
    void Loop();

    ~Engine();
};


#endif //ANTSIMULATOR_ENGINE_HPP
