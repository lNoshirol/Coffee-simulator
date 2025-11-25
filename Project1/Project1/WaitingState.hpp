#pragma once
#include "State.hpp"

class WaitingState : public GameState {
public:
    void update(GameManager& game) override;
};
