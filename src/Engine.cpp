//
// Created by Michin on 21.06.2024.
//

#include "Engine.hpp"

Engine::Engine() {

    //TODO: Init ants
    ants.emplace_back();
}

void Engine::Loop() {
    window.processEvents(ants);
}
