//
// Created by Michin on 20.06.2024.
//

#include "MainWindow.hpp"

MainWindow::MainWindow() {
    window.setFramerateLimit(144);
}

void MainWindow::processEvents(std::vector<Ant> & ants) {

    // deactivate its OpenGL context
    window.setActive(false);

    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        window.clear(sf::Color::Cyan);

        DrawAnts(ants);

        window.display();
    }
}

void MainWindow::DrawAnts(std::vector<Ant> & ants) {
    for(auto ant : ants)
    {
        ant.drawAnt(&window);
    }
}

//TODO: Implement
//void MainWindow::DrawAntsThread(std::vector<Ant> &ants) {
//    // launch the rendering thread
//    sf::Thread thread(&DrawAnts, &ants);
//    thread.launch();
//}
