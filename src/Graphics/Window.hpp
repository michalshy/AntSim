//
// Created by Michin on 20.06.2024.
//

#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

#include <memory>
#include "../Simulation/Anthill.hpp"
#include "../Simulation/Environment/Environment.hpp"
#include "Views/AntView.hpp"
#include "Views/UiView.hpp"
#include "SFML/Graphics.hpp"
#include "../Globals.hpp"
#include <cmath>

class Window{
    ///Window section
    sf::RenderWindow window;

    ///AntView
    AntView ant_view;
    bool dragging;
    sf::Vector2i mouse_pos;

    ///For background
    sf::FloatRect f_bounds;
    sf::IntRect i_bounds;
    sf::Sprite background;
    float view_offset_y;
    float sprite_offset_y;
    u32 texture_height;

    ///UiView
    UiView ui_view;
public:
    Window(std::shared_ptr<sf::Texture> _background_tex);
    void Draw(Anthill & ants, Environment & env);
    sf::RenderWindow &GetWindow(){ return window; }
    bool SetActive(bool state);
    bool IsOpen(){ return window.isOpen(); }
    void ProcessEvents();
    void SetViewOnAnts();
    void ZoomViewAt(sf::Vector2i pixel, float zoom);
    void MoveRelativeToMouse();
    void AdjustOnResize();
    void SetMousePos(sf::Vector2i mouse_pos_proc);
    void SetDragging(bool state);
};

#endif //__WINDOW_HPP__
