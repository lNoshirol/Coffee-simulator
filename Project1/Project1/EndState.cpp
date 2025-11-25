#include <iostream>
#include "EndState.hpp"
#include "GameManager.hpp"

void EndState::update(GameManager& game) {
    std::cout << "\nFin de journee\n";
    std::cout << "Score final : " << game.getScore() << "\n";
    std::cout << "Merci d'avoir joue !\n";

    game.changeState(nullptr);
}
