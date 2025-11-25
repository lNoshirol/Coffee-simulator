#include <iostream>
#include <string>
#include "PreparingState.hpp"
#include "WaitingState.hpp"
#include "EndState.hpp"
#include "DrinkFactory.hpp"
#include "Drink.hpp"
#include "GameManager.hpp"

void PreparingState::update(GameManager& game) {
    std::cout << "\nPréparation du Pumpkin Latte\n";

    Drink* drink = DrinkFactory::create("pumpkin");
    std::string input;

    for (auto& step : drink->getSteps()) {
        std::cout << "Étape" << step << "\n";
        std::cout << "> ";
        std::getline(std::cin, input);

        if (input != step) {
            std::cout << "Recette ratee !\n";
            delete drink;
            game.reduceGuest(1);
            game.changeState(std::make_unique<WaitingState>());
            return;
        }
    }

    std::cout << "Boisson réussie ! +10 points\n";
    game.addScore(10);
    game.reduceGuest(1);

    delete drink;

    game.changeState(std::make_unique<WaitingState>());
}
