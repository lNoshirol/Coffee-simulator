#include <iostream>
#include <algorithm>
#include "Shop.hpp"

void Shop::open(GameManager& game)
{
    while (true)
    {
        std::cout << "\n=== SHOP ===\nQuel ingredient voulez-vous acheter ? (exit pour quitter) ";
        std::string want;
        std::getline(std::cin, want);

        if (want == "exit")
            break;

        Ingredient buyIng;
        if (want != "eau" && stringToIngredient(want, buyIng))
        {
            int price = ingredientPrice(buyIng);

            std::cout << "Combien ? (prix unitaire : " << price << ") ";
            std::string numberStr;
            std::getline(std::cin, numberStr);

            if (!std::all_of(numberStr.begin(), numberStr.end(), ::isdigit))
            {
                std::cout << "Vous devez entrer un nombre valide\n";
                continue;
            }

            int number = std::stoi(numberStr);
            int total = number * price;

            if (game.getMoney() < total)
            {
                std::cout << "Vous n'avez pas assez d'argent ! Il faut " << total << ".\n";
                continue;
            }

            game.addMoney(-total);
            game.addStock(buyIng, number);

            std::cout << "Vous avez achete " << number << " " << ingredientToString(buyIng) << " pour " << total << " argent !\n";
        }
        else if (want == "eau")
        {
            std::cout << "Vous avez deja de l'eau à l'infini.\n";
        }
        else
        {
            std::cout << "Ingredient inconnu.\n";
        }
    }

    std::cout << "(Retour à l’etape en cours)\n\n";
}
