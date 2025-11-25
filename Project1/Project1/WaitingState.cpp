#include <iostream>
#include "WaitingState.hpp"
#include "PreparingState.hpp"
#include "EndState.hpp"
#include "GameManager.hpp"

void WaitingState::update(GameManager& game) {
    if (game.getRemainingGuest() <= 0) {
        game.changeState(std::make_unique<EndState>());
        return;
    }

    std::cout << "\nUn client arrive ! Il veut un Pumpkin Latte\n";
    std::cout << "Client restant : " << game.getRemainingGuest() << "\n";
    std::cout << "Score : " << game.getScore() << "\n";

    game.changeState(std::make_unique<PreparingState>());
}
