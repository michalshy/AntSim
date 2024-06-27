//
// Created by Michin on 21.06.2024.
//

#include "Engine.hpp"

void Engine::ThreadedDraw(Engine* eng)
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
    float delta;
    mainWindow->SetActive(true);
    //Ready thread
    sf::Thread antThread(&(ThreadedDraw), this);
    while(mainWindow->IsOpen())
    {
        Timer::Restart();
        //antThread.launch();
        ants->UpdateAnts();
        mainWindow->Draw(*ants);
        //antThread.wait();
        mainWindow->SetViewOnAnts();
        mainWindow->ProcessEvents();
    }
}

Engine::~Engine()
{
    delete mainWindow;
    delete tM;
    delete ants;
}
