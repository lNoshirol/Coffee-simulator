#include "GameManager.hpp"
#include "State.hpp"
#include "WaitingState.hpp"

GameManager::GameManager() {}

GameManager::~GameManager() = default;

void GameManager::start() {
    changeState(std::make_unique<WaitingState>());
    while (currentState != nullptr) {
        currentState->update(*this);
    }
}

void GameManager::changeState(std::unique_ptr<GameState> newState) {
    currentState = std::move(newState);
}

void GameManager::addScore(int value) {
    score += value;
}

int GameManager::getScore() const {
    return score;
}

void GameManager::reduceGuest(int value) {
    remainingGuest -= value;
}

int GameManager::getRemainingGuest() const {
    return remainingGuest;
}
