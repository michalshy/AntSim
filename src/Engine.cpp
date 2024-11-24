//
// Created by Michin on 21.06.2024.
//

#include "Engine.hpp"
#include <iostream>

void Engine::ThreadedAnts(Engine* eng) {
    eng->ants->UpdateAnts(eng->delta_timer.GetDt());
}

Engine::Engine() {
    delta_timer = Timer();
    input_manager = std::make_unique<InputManager>();
    texture_manager = std::make_unique<TextureManager>();
    window = std::make_unique<Window>(texture_manager->getFromId(TexCodes::BACKGROUND));
    ants = std::make_unique<Anthill>(texture_manager->getFromId(TexCodes::ANT));
}

void Engine::Loop() {
    window->SetActive(true);
    delta_timer.Restart();
    //Ready thread
    sf::Thread ant_thread(&(ThreadedAnts), this);
    while(window->IsOpen())
    {
        //determine timestep TODO: WRITE APPROPRIATE HANDLER
        delta_timer.CheckTimestep();
        //start thread
        ant_thread.launch();
        //set view
        window->SetViewOnAnts();
        //check for events
        window->ProcessEvents();
        //input managing
        input_manager->CheckInputs(*window);
        //draw
        window->Draw(*ants);
        //drawing and updating in parallel
        ant_thread.wait();
    }
}

