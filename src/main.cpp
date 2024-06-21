#include "Engine.hpp"

std::vector<MyTex> TextureManager::texes;

int main()
{
    Engine eng = Engine();
    eng.Loop();
}