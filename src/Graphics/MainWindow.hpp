//
// Created by Michin on 20.06.2024.
//

#ifndef ANTSIMULATOR_MAINWINDOW_HPP
#define ANTSIMULATOR_MAINWINDOW_HPP

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "../Simulation/Entities/Ant.hpp"
#include <thread>
#include <iostream>


class MainWindow {
    sf::RenderWindow window = sf::RenderWindow{ { 1920u, 1080u }, "AntSimulator" };
public:
    MainWindow();
    void Draw(std::vector<Ant> & ants);
    //void DrawAntsThread(std::vector<Ant> & ants);
};


#endif //ANTSIMULATOR_MAINWINDOW_HPP
