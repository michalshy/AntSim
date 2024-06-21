//
// Created by Michin on 21.06.2024.
//

#include "TextureManager.hpp"

void TextureManager::addTexes() {
    texes.push_back(AntTexture()); //ant on 0
}

MyTex TextureManager::getTex(int in) {
    return texes[in];
}
