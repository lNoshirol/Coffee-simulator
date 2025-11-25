#pragma once
#include "State.hpp"

class EndState : public GameState {
public:
    void update(GameManager& game) override;
};
