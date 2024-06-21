//
// Created by Michin on 21.06.2024.
//

#include "Engine.hpp"

Engine::Engine() {
    ants.emplace_back(tM.getFromId(TexCodes::ANT));
}

void Engine::Loop() {
    window.Draw(ants);
}

Engine::~Engine() = default;
