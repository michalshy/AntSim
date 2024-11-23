#ifndef __VIEW_HPP__
#define __VIEW_HPP__

#include "SFML/Graphics.hpp"

class View {
    sf::View view;
public:
    explicit View() = default;
    const void SetView(const sf::View& _view){ view = _view; }
    sf::View& ReturnView(){ return view; }
};


#endif //ANTSIMULATOR_UIVIEW_HPP
