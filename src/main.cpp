#include "Engine.hpp"
#include "Logic/Timer.hpp"

sf::Clock Timer::clk;
sf::Time Timer::dt;

int main()
{
    Engine eng = Engine();
    eng.Loop();
}