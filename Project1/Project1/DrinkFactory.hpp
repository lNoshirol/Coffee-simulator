#pragma once
#include <string>
#include "Drink.hpp"

class DrinkFactory {
public:
    static Drink* create(const std::string& type);
};
