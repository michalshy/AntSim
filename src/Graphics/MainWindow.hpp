//
// Created by Michin on 20.06.2024.
//

#ifndef ANTSIMULATOR_MAINWINDOW_HPP
#define ANTSIMULATOR_MAINWINDOW_HPP

#include "../Simulation/Anthill.hpp"
#include "Views/AntView.hpp"
#include "Views/UiView.hpp"
#include "SFML/Graphics.hpp"
#include "../Globals.hpp"
#include <cmath>

class MainWindow{
    //Window section
    sf::RenderWindow window = sf::RenderWindow{ { WindowParams::WIDTH, WindowParams::HEIGHT }, "AntSimulator"};

    //AntView
    AntView antV;
    bool dragging;
    sf::Vector2i mousePos;

    //For background
    sf::FloatRect fBounds;
    sf::IntRect iBounds;
    sf::Sprite background;
    float viewOffsetY;
    float spriteOffsetY;
    u32 textureHeight;

    //UiView
    UiView uiView;
public:
    MainWindow(sf::Texture * _backgroundTex);
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
    void SetMousePos(sf::Vector2i mousePosProc);
    void SetDragging(bool state);
};

#endif //ANTSIMULATOR_MAINWINDOW_HPP
