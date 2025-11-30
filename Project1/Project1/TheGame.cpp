#include <iostream>
#include <string>
#include "GameManager.hpp"

int main() 
{
    while (true)
    {
        std::cout << "Pour commencer taper : start\n\nPour fermer taper : end\n\n";

        std::string input;
        std::getline(std::cin, input);

        if (input == "start") {
            GameManager game;
            game.start();
        }
        else if (input == "end") {
            return 0;
        }
        else {
            std::cout << "Commande Inconnue\n\n";
        }
    }
}