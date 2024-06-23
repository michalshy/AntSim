//
// Created by Michin on 21.06.2024.
//

#include "Engine.hpp"

void Engine::ThreadedDraw(Engine* eng)
{
    eng->window->Draw(*eng->ants);
}

Engine::Engine() {
    window = new MainWindow();
    tM = new TextureManager();
    ants = new Anthill(tM->getFromId(TexCodes::ANT));
}

void Engine::Loop() {
    window->SetActive(false);

    sf::Thread drawThread(&(ThreadedDraw), this);
    drawThread.launch();

    while(window->IsOpen())
    {
        window->ProcessEvents();
    }
}

Engine::~Engine()
{
    delete window;
    delete tM;
    delete ants;
}
