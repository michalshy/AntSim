//
// Created by Michin on 24.06.2024.
//

#ifndef ANTSIMULATOR_TIMER_HPP
#define ANTSIMULATOR_TIMER_HPP

#include "SFML/System.hpp"
#include "../Globals.hpp"

class Timer {
    sf::Clock clk;
    sf::Time dt;
public:
    Timer();
    const void CheckTimestep();
    const sf::Time GetElapsed(){ return clk.getElapsedTime(); }
    const void Restart(){ dt = clk.restart(); }
    const sf::Time GetDt(){ return dt; }
};


#endif //ANTSIMULATOR_TIMER_HPP
