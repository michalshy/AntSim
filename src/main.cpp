#include "Engine.hpp"

int main()
{
    sf::Clock clk = sf::Clock();

    Engine eng = Engine(clk);
    eng.Loop();
}