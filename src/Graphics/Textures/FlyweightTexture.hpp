//
// Created by Michin on 21.06.2024.
//

#ifndef ANTSIMULATOR_FLYWEIGHTTEXTURE_HPP
#define ANTSIMULATOR_FLYWEIGHTTEXTURE_HPP
#include "SharedState.hpp"

class FlyweightTexture {
private:
    SharedState *shared_state_;

public:
    FlyweightTexture(const SharedState *shared_state) : shared_state_(new SharedState(*shared_state))
    {

    }
    FlyweightTexture(const FlyweightTexture &other) : shared_state_(new SharedState(*other.shared_state_))
    {

    }
    ~FlyweightTexture()
    {
        delete shared_state_;
    }
    SharedState *shared_state() const
    {
        return shared_state_;
    }
    sf::Texture retTex()
    {
        return shared_state_->tex;
    }
};


#endif //ANTSIMULATOR_FLYWEIGHTTEXTURE_HPP
