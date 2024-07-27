//
// Created by Michin on 20.06.2024.
//

#ifndef ANTSIMULATOR_MAINWINDOW_HPP
#define ANTSIMULATOR_MAINWINDOW_HPP

#include "../Simulation/Anthill.hpp"
#include "Views/AntView.hpp"
#include "Views/UiView.hpp"
#include "../Globals.hpp"

class MainWindow{
    sf::RenderWindow window = sf::RenderWindow{ { WindowParams::width, WindowParams::height }, "AntSimulator"};
    AntView antV;
    bool dragging;
    sf::Vector2i mousePos;
public:
    MainWindow();
    void Draw(Anthill & ants);
    sf::RenderWindow &GetWindow(){ return window; }
    bool SetActive(bool state);
    bool IsOpen(){ return window.isOpen(); }
    void ProcessEvents();
    void SetViewOnAnts();
    void InputManaging();
    void ZoomViewAt(sf::Vector2i pixel, float zoom);
    void MoveRelativeToMouse();
    void AdjustOnResize();
};

#endif //ANTSIMULATOR_MAINWINDOW_HPP
