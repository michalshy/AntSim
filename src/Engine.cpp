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
    tM = new TextureManager();
    mainWindow = new MainWindow(tM->getFromId(TexCodes::BACKGROUND));
    ants = new Anthill(tM->getFromId(TexCodes::ANT));
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
        mainWindow->InputManaging();
        //draw
        mainWindow->Draw(*ants);
        //drawing and updating in parallel
        antThread.wait();
        
    }
}

Engine::~Engine()
{
    delete mainWindow;
    delete tM;
    delete ants;
}
