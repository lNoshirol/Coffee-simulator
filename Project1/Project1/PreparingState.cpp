#include <iostream>
#include <string>
#include "PreparingState.hpp"
#include "WaitingState.hpp"
#include "EndState.hpp"
#include "DrinkFactory.hpp"
#include "Drink.hpp"
#include "GameManager.hpp"
#include "Shop.hpp"
#include <vector>
#include <random>

void PreparingState::update(GameManager& game)
{
    // Génère les boisson
    std::vector<Drink*> drinks = DrinkFactory::create("all");
    if (drinks.empty()) {
        std::cout << "Aucune boisson disponible\n";
        game.changeState(std::make_unique<WaitingState>());
        return;
    }

    // Choisis les boisson avec un random (plus afficace qu'un random de base)
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, drinks.size() - 1);
    Drink* drink = drinks[dist(gen)];

    std::cout << "\nLe client veut un " << drink->getName() << "\n";

    std::string input;
    const auto& steps = drink->getSteps();
    int stepIndex = 0;

    while (stepIndex < steps.size())
    {
        Ingredient step = steps[stepIndex];

        std::cout << "Etape " << (stepIndex + 1)
            << " - ingredient attendu : " << ingredientToString(step) << "\n> ";

        std::getline(std::cin, input);

        // Ouvre le shop
        if (input == "shop")
        {
            Shop::open(game);
            continue;
        }

        // Stock
        if (input == "stock")
        {
            std::cout << "\n==== Stock actuel des ingredient ====\n";
            for (const auto& item : game.getFullStock())
            {
                const Ingredient& ing = item.first;
                std::string ingredient = ingredientToString(ing);
                int quantity = item.second;

                std::cout << "- " << ingredient << " : " << quantity << "\n";
            }
            std::cout << "=======================================\n\n";

            std::cout << "(Retour à l’etape en cours)\n\n";
            continue;
        }


        // Convertion en ingrédient
        Ingredient given;
        if (!stringToIngredient(input, given)) {
            std::cout << "Entree inconnue\nRecette ratee\n";
            delete drink;
            game.reduceGuest(1);
            game.changeState(std::make_unique<WaitingState>());
            return;
        }

        // Vérifie si c'est le bon ingrédient
        if (given != step) {
            std::cout << "Mauvais ingredient, attendu : "
                << ingredientToString(step) << "\nRecette ratee\n";
            delete drink;
            game.reduceGuest(1);
            game.changeState(std::make_unique<WaitingState>());
            return;
        }

        // Consomme l'ingrédient a part si il n'en a plus ou si c'est de l'eau
        if (step != Ingredient::Eau) {
            if (!game.consumeIngredient(step, 1)) {
                std::cout << "Vous n'avez plus de " << ingredientToString(step) << "\nRecette ratee\n";
                delete drink;
                game.reduceGuest(1);
                game.changeState(std::make_unique<WaitingState>());
                return;
            }
        }

        // Étape suivante
        stepIndex++;
    }

    std::cout << "Boisson reussie ! +" << drink->getPrice() << " argent\n";
    game.addMoney(drink->getPrice());
    game.reduceGuest(1);

    delete drink;
    game.changeState(std::make_unique<WaitingState>());
}
