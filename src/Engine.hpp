//
// Created by Michin on 21.06.2024.
//

#ifndef ANTSIMULATOR_ENGINE_HPP
#define ANTSIMULATOR_ENGINE_HPP

#include "Graphics/MainWindow.hpp"
#include "Graphics/Textures/TextureManager.hpp"
#include "Simulation/Anthill.hpp"
#include "Logic/Timer.hpp"

class Engine {
    static void ThreadedDraw(Engine* eng);
public:
    explicit Engine();
    void Loop();
    ~Engine();
protected:
    TextureManager * tM;
    MainWindow * window;
    Anthill * ants;
};


#endif //ANTSIMULATOR_ENGINE_HPP
