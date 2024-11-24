#include "InputManager.hpp"

void InputManager::CheckInputs(Window& window)
{
    if(sf::Mouse::isButtonPressed((sf::Mouse::Middle)))
    {
        window.SetMousePos(sf::Mouse::getPosition());
        window.SetDragging(true);
    }
    else
        window.SetDragging(false);
    if(sf::Mouse::isButtonPressed((sf::Mouse::Left)))
        window.SetDrawing(true);
    else
        window.SetDrawing(false);

}
