//
// Created by Michin on 21.06.2024.
//

#include "Engine.hpp"

void Engine::ThreadedAnts(Engine* eng)
{
    eng->ants->UpdateAnts();
}

Engine::Engine() {
    mainWindow = new MainWindow();
    tM = new TextureManager();
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
        //draw
        mainWindow->Draw(*ants);
        //drawing and updating in parallel
        antThread.wait();
        //set view
        mainWindow->SetViewOnAnts();
        //check for events
        mainWindow->ProcessEvents();
    }
}

Engine::~Engine()
{
    delete mainWindow;
    delete tM;
    delete ants;
}
