//
// Created by Michin on 20.06.2024.
//

#ifndef ANTSIMULATOR_MAINWINDOW_HPP
#define ANTSIMULATOR_MAINWINDOW_HPP

#include "../../Simulation/Anthill.hpp"
#include "../Window.hpp"

class MainWindow : public Window{
public:
    MainWindow();
    void Draw(Anthill & ants);
};

#endif //ANTSIMULATOR_MAINWINDOW_HPP
