//
// Created by Michin on 20.06.2024.
//

#include "MainWindow.hpp"

MainWindow::MainWindow() = default;

void MainWindow::Draw(Anthill & ants){
        GetWindow().clear(sf::Color::Cyan);
        for(Ant& ant : ants.GetAnts())
        {
            ant.DrawAnt(this->GetWindow());
        }
        GetWindow().display();
}





