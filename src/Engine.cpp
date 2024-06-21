//
// Created by Michin on 21.06.2024.
//

#include "Engine.hpp"

Engine::Engine() {
    ants.emplace_back(tM.getFromId(TexCodes::ANT));
}

void Engine::Loop() {
    window.SetActive(false);

    while(window.IsOpen())
    {
        window.ProcessEvents();
        window.Draw(ants);
    }
}

Engine::~Engine() = default;
