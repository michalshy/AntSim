//
// Created by Michin on 21.06.2024.
//

#ifndef ANTSIMULATOR_ENGINE_HPP
#define ANTSIMULATOR_ENGINE_HPP

#include <memory>
#include "Graphics/MainWindow.hpp"
#include "Graphics/Textures/TextureManager.hpp"
#include "Simulation/Anthill.hpp"
#include "Logic/Timer.hpp"
#include "SFML/System.hpp"
#include "Logic/Managers/InputManager.hpp"

class Engine {
    static void ThreadedAnts(Engine* eng);
public:
    explicit Engine();
    void Loop();
protected:
    std::unique_ptr<TextureManager> tM;
    std::unique_ptr<MainWindow> mainWindow;
    std::unique_ptr<Anthill> ants;
    std::unique_ptr<InputManager> inputManager;
};


#endif //ANTSIMULATOR_ENGINE_HPP
