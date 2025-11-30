#include "GameManager.hpp"
#include "State.hpp"
#include "WaitingState.hpp"

GameManager::GameManager() {}

GameManager::~GameManager() = default;

// Initialisation de la partie
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

// Chagement d'état
void GameManager::changeState(std::unique_ptr<GameState> newState) {
    currentState = std::move(newState);
}

// Rajoute de l'argent
void GameManager::addMoney(int value) {
    money += value;
}

// Permet de savoir le nombre d'argent actuel
int GameManager::getMoney() const {
    return money;
}

// Réduit le nombre de client
void GameManager::reduceGuest(int value) {
    remainingGuest -= value;
}

// Augmente le nombre de client
void GameManager::addGuest(int value) {
    remainingGuest += value;
}

// Permet de savoir le nombre de client actuel
int GameManager::getRemainingGuest() const {
    return remainingGuest;
}

// Permet de passez au jour suivant
void GameManager::addDay() {
    actualDay += 1;
}

// Permet de savoir quel jour on est
int GameManager::getActualDay() const {
    return actualDay;
}

// Permet de savoir quel nombre d'un ingrédient il reste
int GameManager::getStock(Ingredient ing) const {
    auto it = stock.find(ing);
    return (it != stock.end() ? it->second : 0);
}

// Rajoute des ingrédient
void GameManager::addStock(Ingredient ing, int amount) {
    stock[ing] += amount;
}

// Retire un ingrédient
bool GameManager::consumeIngredient(Ingredient ing, int amount) {
    auto it = stock.find(ing);
    if (it == stock.end() || it->second < amount) return false;
    it->second -= amount;
    return true;
}
