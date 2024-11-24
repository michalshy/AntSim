//
// Created by Michin on 23.06.2024.
//

#ifndef __ENVIRONMENT_HPP__
#define __ENVIRONMENT_HPP__

#include "SFML/Graphics.hpp"
#include "../../Globals.hpp"
#include "../../Common/Markers/Marker.hpp"

struct Bounds {
    sf::RectangleShape upper;
    sf::RectangleShape right;
    sf::RectangleShape left;
    sf::RectangleShape down;
};

class Environment{
    Bounds bounds;
public:
    explicit Environment();
    void Draw(sf::RenderWindow & window);
private:
    void DrawBounds(sf::RenderWindow & window);
};


#endif //__ENVIRONMENT_HPP__