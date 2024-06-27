//
// Created by Michin on 20.06.2024.
//

#include "MainWindow.hpp"

MainWindow::MainWindow()
{
    window.setFramerateLimit(144);
    antV = AntView();
}

void MainWindow::Draw(Anthill & ants){
        GetWindow().clear(sf::Color::Cyan);
        for(Ant& ant : ants.GetAnts())
        {
            ant.DrawAnt(this->GetWindow());
        }
        GetWindow().display();
}

bool MainWindow::SetActive(bool state) {
    return window.setActive(state);
}

void MainWindow::ProcessEvents() {
    for (auto event = sf::Event{}; window.pollEvent(event);)
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
        if(event.type == sf::Event::Resized)
        {
        }
    }
}

void MainWindow::SetViewOnAnts() {
    window.setView(antV.ReturnView());
}





