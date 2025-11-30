#include <iostream>
#include "EndState.hpp"
#include "WaitingState.hpp"
#include "GameManager.hpp"

void EndState::update(GameManager& game)
{
    std::cout << "\nFin de journee\n";
    std::cout << "Argent final : " << game.getMoney() << "\n\n";
    std::cout << "Pour continuer taper : continue\n\nPour retourner au menu taper : menu\n\n";

    while (true)
    {
        std::string input;
        std::getline(std::cin, input);

        if (input == "continue") {
            game.addGuest(6);
            game.addDay();
            game.changeState(std::make_unique<WaitingState>());
            break;
        }
        else if (input == "menu") {
            std::cout << "\nMerci d'avoir joue\n\n\n\n\n\n\n\n\n\n";
            game.changeState(nullptr);
            break;
        }
        else {
            std::cout << "Commande Inconnue\n\n";
        }
    }
}
