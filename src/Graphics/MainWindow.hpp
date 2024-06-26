//
// Created by Michin on 20.06.2024.
//

#ifndef ANTSIMULATOR_MAINWINDOW_HPP
#define ANTSIMULATOR_MAINWINDOW_HPP

#include "../Simulation/Anthill.hpp"
#include "Views/AntView.hpp"
#include "Views/UiView.hpp"


class MainWindow{
    sf::RenderWindow window = sf::RenderWindow{ { 1600u, 800u }, "AntSimulator", sf::Style::Titlebar | sf::Style::Close};
    AntView antV;
public:
    MainWindow();
    void Draw(Anthill & ants);
    sf::RenderWindow &GetWindow(){ return window; }
    bool SetActive(bool state);
    bool IsOpen(){ return window.isOpen(); }
    void ProcessEvents();
    void SetViewOnAnts();
};

#endif //ANTSIMULATOR_MAINWINDOW_HPP
