#pragma once
#include <memory>

class GameState;

class GameManager {
public:
    GameManager();
    ~GameManager();

    void start();
    void changeState(std::unique_ptr<GameState> newState);

    void addScore(int value);
    int getScore() const;

    void reduceGuest(int value);
    int getRemainingGuest() const;

private:
    std::unique_ptr<GameState> currentState;
    int score = 0;
    int remainingGuest = 6;
};
