//
// Created by Michin on 21.06.2024.
//

#include "Engine.hpp"
#include <iostream>

void Engine::ThreadedAnts(Engine* eng) {
    eng->ants->UpdateAnts(eng->delta_timer.GetDt());
}

void Engine::ThreadedEnvironment(Engine* eng) {
    eng->environment->Update();
}

Engine::Engine() {
    delta_timer = Timer();
    input_manager = std::make_unique<InputManager>();
    texture_manager = std::make_unique<TextureManager>();
    window = std::make_unique<Window>(texture_manager->getFromId(TexCodes::BACKGROUND_TEX));
    ants = std::make_unique<Anthill>(texture_manager->getFromId(TexCodes::ANT_TEX));
    environment = std::make_unique<Environment>();
}

void Engine::Loop() {
    window->SetActive(true);
    delta_timer.Restart();
    //Ready thread ants
    sf::Thread ant_thread(&(ThreadedAnts), this);
    //Ready thread environment
    sf::Thread env_thread(&(ThreadedEnvironment), this);
    while(window->IsOpen())
    {
        //determine timestep TODO: WRITE APPROPRIATE HANDLER
        delta_timer.CheckTimestep();
        //start threads
        ant_thread.launch();
        env_thread.launch();
        //check for events
        window->ProcessEvents();
        //input managing
        input_manager->CheckInputs(*window);
        //draw
        window->Draw(*ants, *environment);
        //drawing and updating in parallel
        ant_thread.wait();
        env_thread.wait();
    }
}

