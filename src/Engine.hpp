//
// Created by Michin on 21.06.2024.
//

#ifndef ANTSIMULATOR_ENGINE_HPP
#define ANTSIMULATOR_ENGINE_HPP

#include "Graphics/Windows/MainWindow.hpp"
#include "Graphics/Textures/TextureManager.hpp"
#include "Simulation/Anthill.hpp"
#include "Logic/Timer.hpp"
#include "Graphics/Windows/UiWindow.hpp"
class Engine {
    static void ThreadedDraw(Engine* eng);
public:
    explicit Engine();
    void Loop();
    ~Engine();
protected:
    TextureManager * tM;
    MainWindow * mainWindow;
    UIWindow * uiWindow;
    Anthill * ants;
};


#endif //ANTSIMULATOR_ENGINE_HPP
