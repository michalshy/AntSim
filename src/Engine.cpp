//
// Created by Michin on 21.06.2024.
//

#include "Engine.hpp"

Engine::Engine() {
    factory = new FactoryTexture({{"src/Graphics/Textures/Images/ant.png"}});
    ants.emplace_back(factory);
}

void Engine::Loop() {
    window.Draw(ants);
}

Engine::~Engine() {
    delete factory;
}
