#include "Environment.hpp"

Environment::Environment()
{
    pheromones.push_back(Marker(sf::CircleShape(10), 100, 100, 100, 100));
    pheromones.push_back(Marker(sf::CircleShape(10), 200, 200, 255, 100));
    pheromones.push_back(Marker(sf::CircleShape(10), 300, 300, 255, 100));

    bounds.upper.setPosition(sf::Vector2f(WINDOW::X_ZERO, WINDOW::Y_ZERO));
    bounds.upper.setSize(sf::Vector2f(WINDOW::WIDTH, WINDOW::BOUND_THICKNESS));
    bounds.upper.setFillColor(sf::Color::Black);

    bounds.left.setPosition(sf::Vector2f(WINDOW::X_ZERO, WINDOW::Y_ZERO));
    bounds.left.setSize(sf::Vector2f(WINDOW::BOUND_THICKNESS, WINDOW::HEIGHT));
    bounds.left.setFillColor(sf::Color::Black);

    bounds.right.setPosition(WINDOW::X_END, WINDOW::Y_ZERO);
    bounds.right.setSize(sf::Vector2f(WINDOW::BOUND_THICKNESS, WINDOW::HEIGHT));
    bounds.right.setFillColor(sf::Color::Black);

    bounds.down.setPosition(WINDOW::X_ZERO, WINDOW::Y_END);
    bounds.down.setSize(sf::Vector2f(WINDOW::WIDTH, WINDOW::BOUND_THICKNESS));
    bounds.down.setFillColor(sf::Color::Black);
}




void Environment::Draw(sf::RenderWindow &window, bool drawing)
{
    DrawBounds(window);
}

void Environment::Update()
{
    if(!pheromones.empty())
        for(auto& m : pheromones)
        {
            m.update();
        }
}

void Environment::DrawBounds(sf::RenderWindow &window)
{
    window.draw(bounds.upper);
    window.draw(bounds.left);
    window.draw(bounds.right);
    window.draw(bounds.down);

    if(!pheromones.empty())
        for(auto& m : pheromones)
        {
            m.draw(window);
        }
}
