#include <iostream>
#include <string>
#include "PreparingState.hpp"
#include "WaitingState.hpp"
#include "EndState.hpp"
#include "DrinkFactory.hpp"
#include "Drink.hpp"
#include "GameManager.hpp"
#include <vector>
#include <random>

void PreparingState::update(GameManager& game) {

    /*std::vector<Drink*> CofeList = { 
        DrinkFactory::create("pumpkin"), 
        DrinkFactory::create("GamerCoffe"),
        DrinkFactory::create("GamerCoffe"),
        DrinkFactory::create("GamerCoffe"),
        DrinkFactory::create("GamerCoffe"),
        DrinkFactory::create("GamerCoffe"),
        DrinkFactory::create("GamerCoffe"),
        DrinkFactory::create("GamerCoffe")
    };*/

    
    
    Drink* drink;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, DrinkFactory::create().size());
    int randInt = dist(gen);


    std::cout << "\nPréparation du Pumpkin Latte\n";

    drink = CofeList[randInt];

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

    std::cout << "Boisson réussie ! +";
    std::cout << drink->getPrice();
    std::cout << " argent\n";
    game.addScore(drink->getPrice());
    game.reduceGuest(1);

    delete drink;

    game.changeState(std::make_unique<WaitingState>());
}
