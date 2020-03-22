//
// Created by Milton Loayza on 4/25/15.
//

#include "GameComponent.h"

namespace EasyOpenGL
{
    GameComponent::GameComponent()
            : enabled(true)
    {
    }

    GameComponent::~GameComponent()
    {
    }

    bool GameComponent::isEnabled() const
    {
        return enabled;
    }

    void GameComponent::setEnabled(bool enabled)
    {
        this->enabled = enabled;
    }

    void GameComponent::initialize() {
    }

    void GameComponent::update() {
    }

    void GameComponent::draw() {
    }

}
