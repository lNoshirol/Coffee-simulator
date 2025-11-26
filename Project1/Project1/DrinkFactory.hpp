#pragma once
#include <string>
#include "Drink.hpp"

class DrinkFactory {
public:
    static std::vector<Drink*> create(const std::string& type);
};
