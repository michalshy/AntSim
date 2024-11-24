//
// Created by Michin on 21.06.2024.
//

#ifndef __ENGINE_HPP__
#define __ENGINE_HPP__

#include <memory>
#include "Graphics/Window.hpp"
#include "Graphics/Textures/TextureManager.hpp"
#include "Simulation/Anthill.hpp"
#include "Logic/Timer.hpp"
#include "SFML/System.hpp"
#include "Logic/Managers/InputManager.hpp"

class Engine {
    static void ThreadedAnts(Engine* eng);
    Timer delta_timer;
public:
    explicit Engine();
    void Loop();
protected:
    std::unique_ptr<TextureManager> texture_manager;
    std::unique_ptr<Window> window;
    std::unique_ptr<Anthill> ants;
    std::unique_ptr<InputManager> input_manager;
};


#endif //__ENGINE_HPP__
