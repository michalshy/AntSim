//
// Created by Michin on 21.06.2024.
//

#ifndef ANTSIMULATOR_TEXTUREMANAGER_HPP
#define ANTSIMULATOR_TEXTUREMANAGER_HPP
#include <vector>
#include "Textures/AntTexture.hpp"
#include "Textures/MyTex.hpp"

class TextureManager {
static std::vector<MyTex> texes;
public:
    void addTexes();
    MyTex getTex(int in);
    static std::vector<MyTex> returnTexes(){ return texes; }
};

enum TexCodes
{
    ANT = 0,
};



#endif //ANTSIMULATOR_TEXTUREMANAGER_HPP
