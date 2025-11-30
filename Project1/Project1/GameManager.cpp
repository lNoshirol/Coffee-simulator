#include "GameManager.hpp"
#include "State.hpp"
#include "WaitingState.hpp"

GameManager::GameManager() {}

GameManager::~GameManager() = default;

//Initialisation de la partie
void GameManager::start() {

    addStock(Ingredient::Cafe, 5);
    addStock(Ingredient::Lait, 5);
    addStock(Ingredient::The, 3);
    addStock(Ingredient::Sucre, 10);
    addStock(Ingredient::Chocolat, 3);
    addStock(Ingredient::Chantilly, 2);
    addMoney(10);

    changeState(std::make_unique<WaitingState>());
    while (currentState != nullptr) {
        currentState->update(*this);
    }
}

void GameManager::changeState(std::unique_ptr<GameState> newState) {
    currentState = std::move(newState);
}

void GameManager::addMoney(int value) {
    money += value;
}

int GameManager::getMoney() const {
    return money;
}

void GameManager::reduceGuest(int value) {
    remainingGuest -= value;
}

void GameManager::addGuest(int value) {
    remainingGuest += value;
}

int GameManager::getRemainingGuest() const {
    return remainingGuest;
}

void GameManager::addDay() {
    actualDay += 1;
}

int GameManager::getActualDay() const {
    return actualDay;
}

int GameManager::getStock(Ingredient ing) const {
    auto it = stock.find(ing);
    return (it != stock.end() ? it->second : 0);
}

void GameManager::addStock(Ingredient ing, int amount) {
    stock[ing] += amount;
}

bool GameManager::consumeIngredient(Ingredient ing, int amount) {
    auto it = stock.find(ing);
    if (it == stock.end() || it->second < amount) return false;
    it->second -= amount;
    return true;
}
