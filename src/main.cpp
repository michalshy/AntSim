#include "Engine.hpp"
#include "Logic/Timer.hpp"

sf::Clock Timer::clk;
sf::Time Timer::dt;
sf::Time Timer::timePerFrame;

int main()
{
    Engine eng = Engine();
    eng.Loop();
}