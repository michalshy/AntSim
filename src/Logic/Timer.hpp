//
// Created by Michin on 24.06.2024.
//

#ifndef ANTSIMULATOR_TIMER_HPP
#define ANTSIMULATOR_TIMER_HPP

#include "SFML/System.hpp"

class Timer {
    static sf::Clock clk;
    static sf::Time dt;
    static sf::Time timePerFrame;
public:
    Timer();
    static void Init();
    static sf::Time GetElapsed(){ return clk.getElapsedTime(); }
    static void Restart(){ dt = clk.restart(); }
    static sf::Time GetDt(){ return dt; }
    static sf::Time GetPerFrame(){ return timePerFrame; }
};


#endif //ANTSIMULATOR_TIMER_HPP
