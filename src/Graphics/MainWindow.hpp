//
// Created by Michin on 20.06.2024.
//

#ifndef ANTSIMULATOR_MAINWINDOW_HPP
#define ANTSIMULATOR_MAINWINDOW_HPP

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

class MainWindow {
    sf::RenderWindow window = sf::RenderWindow{ { 1920u, 1080u }, "AntSimulator" };
public:
    MainWindow();

    void processEvents();
};


#endif //ANTSIMULATOR_MAINWINDOW_HPP
