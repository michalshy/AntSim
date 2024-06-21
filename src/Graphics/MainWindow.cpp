//
// Created by Michin on 20.06.2024.
//

#include "MainWindow.hpp"

MainWindow::MainWindow() {
    window.setFramerateLimit(144);
}

//TODO: Implement
//void MainWindow::DrawAntsThread(std::vector<Ant> &ants) {
//    // launch the rendering thread
//    sf::Thread thread(&DrawAnts, &ants);
//    thread.launch();
//}


void MainWindow::Draw(std::vector<Ant> &ants){
        window.clear(sf::Color::Cyan);

        for(Ant ant : ants)
        {
            ant.drawAnt(this->window);
        }

        window.display();
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
    }
}



