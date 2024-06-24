//
// Created by Michin on 21.06.2024.
//

#ifndef ANTSIMULATOR_ENGINE_HPP
#define ANTSIMULATOR_ENGINE_HPP

#include "Graphics/MainWindow.hpp"
#include "Graphics/Textures/TextureManager.hpp"
#include "Simulation/Anthill.hpp"

class Engine {
    bool mThreadFlag = false;
    static void ThreadedDraw(Engine* eng);
public:
    explicit Engine(sf::Clock _clk);
    void Loop();
    ~Engine();

    void SetFlag(bool s){ mThreadFlag = s; }
    bool GetFlag() const{ return mThreadFlag; }
protected:
    TextureManager * tM;
    MainWindow * window;
    Anthill * ants;
    sf::Clock * clk;
};


#endif //ANTSIMULATOR_ENGINE_HPP
