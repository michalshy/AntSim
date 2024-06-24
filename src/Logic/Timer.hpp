//
// Created by Michin on 24.06.2024.
//

#ifndef ANTSIMULATOR_TIMER_HPP
#define ANTSIMULATOR_TIMER_HPP

#include "SFML/System.hpp"

class Timer {
    static sf::Clock clk;
    static double dt;
public:
    Timer();
    static sf::Time GetElapsed(){ return clk.getElapsedTime(); }
    static void Restart(){ dt = clk.restart().asMilliseconds(); }
    static double GetDt(){ return dt; }
};


#endif //ANTSIMULATOR_TIMER_HPP
