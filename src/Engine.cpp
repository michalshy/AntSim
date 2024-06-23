//
// Created by Michin on 21.06.2024.
//

#include "Engine.hpp"

void Engine::ThreadedDraw(Engine* eng)
{
    eng->ants->UpdateAnts();
}

Engine::Engine() {
    window = new MainWindow();
    tM = new TextureManager();
    ants = new Anthill(tM->getFromId(TexCodes::ANT));
}

void Engine::Loop() {
    window->SetActive(false);

    sf::Thread antThread(&(ThreadedDraw), this);

    while(window->IsOpen())
    {
        antThread.launch();
        window->Draw(*ants);
        window->ProcessEvents();
        antThread.wait();
    }
}

Engine::~Engine()
{
    delete window;
    delete tM;
    delete ants;
}
