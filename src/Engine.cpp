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
    mainWindow->SetActive(true);
    sf::Thread antThread(&(ThreadedDraw), this);
    //Init timer
    Timer::Init();
    while(mainWindow->IsOpen())
    {
        antThread.launch();
        mainWindow->ProcessEvents();
        mainWindow->Draw(*ants);
        antThread.wait();
        Timer::Restart();
    }
}

Engine::~Engine()
{
    delete mainWindow;
    delete tM;
    delete ants;
}
