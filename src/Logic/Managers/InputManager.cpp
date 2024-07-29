#include "InputManager.hpp"

void InputManager::CheckInputs(MainWindow &mainWin)
{
        if(sf::Mouse::isButtonPressed((sf::Mouse::Middle)))
        {
            mainWin.SetMousePos(sf::Mouse::getPosition());
            mainWin.SetDragging(true);
        }
        else
        {
            mainWin.SetDragging(false);
        }
}
