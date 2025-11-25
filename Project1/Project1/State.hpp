#pragma once

class GameManager;

class GameState {
public:
    virtual ~GameState() = default;
    virtual void update(GameManager& game) = 0;
};
