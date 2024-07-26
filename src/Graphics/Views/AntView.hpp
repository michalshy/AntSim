//
// Created by Michin on 27.06.2024.
//

#ifndef ANTSIMULATOR_ANTVIEW_HPP
#define ANTSIMULATOR_ANTVIEW_HPP

#include "SFML/Graphics.hpp"

class AntView {
    sf::View antV;
public:
    AntView();
    sf::View& ReturnView(){ return antV; }
};


#endif //ANTSIMULATOR_ANTVIEW_HPP
