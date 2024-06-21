//
// Created by Michin on 21.06.2024.
//

#include "Engine.hpp"

Engine::Engine() {
    tM.addTexes();
    //TODO: Init ants
    ants.emplace_back(tM);
}

void Engine::Loop() {
    window.Draw(ants);
}