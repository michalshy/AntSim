//
// Created by Michin on 21.06.2024.
//

#include "Engine.hpp"
#include <iostream>

void Engine::ThreadedAnts(Engine* eng) {
    eng->ants->UpdateAnts(eng->delta_timer.GetDt().asMicroseconds());
}

Engine::Engine() {
    delta_timer = Timer();
    input_manager = std::make_unique<InputManager>();
    texture_manager = std::make_unique<TextureManager>();
    main_window = std::make_unique<MainWindow>(texture_manager->getFromId(TexCodes::BACKGROUND));
    ants = std::make_unique<Anthill>(texture_manager->getFromId(TexCodes::ANT));
}

void Engine::Loop() {
    main_window->SetActive(true);
    //Ready thread
    sf::Thread ant_thread(&(ThreadedAnts), this);
    while(main_window->IsOpen())
    {
        //determine timestep TODO: WRITE APPROPRIATE HANDLER
        delta_timer.CheckTimestep();
        //start thread
        ant_thread.launch();
        //set view
        main_window->SetViewOnAnts();
        //check for events
        main_window->ProcessEvents();
        //input managing
        input_manager->CheckInputs(*main_window);
        //draw
        main_window->Draw(*ants);
        //drawing and updating in parallel
        ant_thread.wait();
    }
}

