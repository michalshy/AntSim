//
// Created by Michin on 21.06.2024.
//

#ifndef ANTSIMULATOR_FACTORYTEXTURE_HPP
#define ANTSIMULATOR_FACTORYTEXTURE_HPP

#include <unordered_map>
#include <string>
#include "FlyweightTexture.hpp"

class FactoryTexture {
    /**
        * @var Flyweight[]
        */
private:
    std::unordered_map<std::string, FlyweightTexture> flyweights_;
    /**
     * Returns a Flyweight's string hash for a given state.
     */
    static std::string GetKey(const SharedState &ss)
    {
        return ss.fileName;
    }

public:
    FactoryTexture(std::initializer_list<SharedState> share_states)
    {
        for (const SharedState &ss : share_states)
        {
            this->flyweights_.insert(std::make_pair<std::string, FlyweightTexture>(this->GetKey(ss), FlyweightTexture(&ss)));
        }
    }

    /**
     * Returns an existing Flyweight with a given state or creates a new one.
     */
    FlyweightTexture GetFlyweight(const SharedState &shared_state)
    {
        std::string key = this->GetKey(shared_state);
        if (this->flyweights_.find(key) == this->flyweights_.end())
        {
            this->flyweights_.insert(std::make_pair(key, FlyweightTexture(&shared_state)));
        }
        return this->flyweights_.at(key);
    }
};


#endif //ANTSIMULATOR_FACTORYTEXTURE_HPP
