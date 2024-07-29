//
// Created by Michin on 27.06.2024.
//

#ifndef ANTSIMULATOR_UIVIEW_HPP
#define ANTSIMULATOR_UIVIEW_HPP

#include "SFML/Graphics.hpp"

class UiView {
    sf::View uiView;
public:
    UiView();
    sf::View ReturnView(){ return uiView; }
};


#endif //ANTSIMULATOR_UIVIEW_HPP
