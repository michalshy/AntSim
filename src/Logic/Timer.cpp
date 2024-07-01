//
// Created by Michin on 24.06.2024.
//

#include "Timer.hpp"

Timer::Timer() = default;

void Timer::Init() {
    clk = sf::Clock();
}

void Timer::CheckTimestep() {
    Timer::Restart();
    if(dt > sf::seconds(0.1))
    {
        dt = sf::Time::Zero;
    }
}
