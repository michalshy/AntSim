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
#include "../Simulation/Anthill.hpp"

class MainWindow {
    sf::RenderWindow window = sf::RenderWindow{ { 1920u, 1080u }, "AntSimulator" };;
public:
    MainWindow();
    sf::RenderWindow & GetWindow(){ return window; }
    void Draw(Anthill & ants);
    bool SetActive(bool state);
    bool IsOpen(){ return window.isOpen(); }
    void ProcessEvents();
};


#endif //ANTSIMULATOR_MAINWINDOW_HPP
