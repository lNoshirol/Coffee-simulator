#pragma once
#include "State.hpp"

class PreparingState : public GameState {
public:
    void update(GameManager& game) override;
};
