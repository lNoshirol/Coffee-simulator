#pragma once
#include <memory>
#include <map>
#include "Ingredient.hpp"

class GameState;

class GameManager {
public:
    GameManager();
    ~GameManager();

    void start();
    void changeState(std::unique_ptr<GameState> newState);

    void addMoney(int value);
    int getMoney() const;

    void reduceGuest(int value);
    void addGuest(int value);
    int getRemainingGuest() const;

    void addDay();
    int getActualDay() const;

    int getStock(Ingredient ing) const;
    const std::map<Ingredient, int>& getFullStock() const { return stock; }
    void addStock(Ingredient ing, int amount);
    bool consumeIngredient(Ingredient ing, int amount);

private:
    std::unique_ptr<GameState> currentState;
    int money = 0;
    int remainingGuest = 6;
    int actualDay = 1;
    std::map<Ingredient, int> stock;
};
