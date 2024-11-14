//
// Created by Michin on 21.06.2024.
//

#include "Engine.hpp"
#include <iostream>

void Engine::ThreadedAnts(Engine* eng)
{
    eng->ants->UpdateAnts();
}

Engine::Engine() {
    inputManager = std::make_unique<InputManager>();
    tM = std::make_unique<TextureManager>();
    mainWindow = std::make_unique<MainWindow>(tM->getFromId(TexCodes::BACKGROUND));
    ants = std::make_unique<Anthill>(tM->getFromId(TexCodes::ANT));
}

void Engine::Loop() {
    //Init timer
    Timer::Init();
    mainWindow->SetActive(true);
    //Ready thread
    sf::Thread antThread(&(ThreadedAnts), this);
    while(mainWindow->IsOpen())
    {
        //determine timestep TODO: WRITE APPROPRIATE HANDLER
        Timer::CheckTimestep();
        //start thread
        antThread.launch();
        //set view
        mainWindow->SetViewOnAnts();
        //check for events
        mainWindow->ProcessEvents();
        //input managing
        inputManager->CheckInputs(*mainWindow);
        //draw
        mainWindow->Draw(*ants);
        //drawing and updating in parallel
        antThread.wait();
        
    }
}

