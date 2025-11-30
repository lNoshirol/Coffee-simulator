#include <iostream>
#include "WaitingState.hpp"
#include "PreparingState.hpp"
#include "EndState.hpp"
#include "GameManager.hpp"

void WaitingState::update(GameManager& game)
{
    if (game.getRemainingGuest() <= 0) {
        game.changeState(std::make_unique<EndState>());
        return;
    }

    if (game.getRemainingGuest() == 6) {

        if (game.getActualDay() == 1) {
            std::cout << "\n\nTuto :\nPour jouer il faut taper les ingredient qui constitue les differentes etapes de la boisson.\n\n";
            std::cout << "Plusieurs commande sont disponible :\npour ouvrir le magasin taper : shop\npour regarder les stock taper : stock\n";
        }

        std::cout << "\n\n\nJour " << game.getActualDay() << "\n";
    }

    std::cout << "\nUn client arrive\n";
    std::cout << "Client restant : " << game.getRemainingGuest() << "\n";
    std::cout << "Argent : " << game.getMoney() << "\n";

    game.changeState(std::make_unique<PreparingState>());
}
