//
// Created by Michin on 20.06.2024.
//

#ifndef ANTSIMULATOR_MAINWINDOW_HPP
#define ANTSIMULATOR_MAINWINDOW_HPP

#include "../Simulation/Anthill.hpp"

class MainWindow{
    sf::RenderWindow window = sf::RenderWindow{ { 1920u, 1080u }, "AntSimulator" };
public:
    MainWindow();
    void Draw(Anthill & ants);
    sf::RenderWindow &GetWindow(){ return window; }
    bool SetActive(bool state);
    bool IsOpen(){ return window.isOpen(); }
    void ProcessEvents();
};

#endif //ANTSIMULATOR_MAINWINDOW_HPP
