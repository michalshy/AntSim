#include "InputManager.hpp"

void InputManager::CheckInputs(MainWindow &main_win)
{
        if(sf::Mouse::isButtonPressed((sf::Mouse::Middle)))
        {
            main_win.SetMousePos(sf::Mouse::getPosition());
            main_win.SetDragging(true);
        }
        else
        {
            main_win.SetDragging(false);
        }
}
