//
// Created by Michin on 21.06.2024.
//
#include "SFML/Graphics.hpp"

struct SharedState
{
    sf::Texture tex;
    std::string fileName;
    SharedState(const std::string & _filename)
    {
        fileName = _filename;
        if(!tex.loadFromFile(_filename))
        {
            //TODO ERROR
        }
    }
};

