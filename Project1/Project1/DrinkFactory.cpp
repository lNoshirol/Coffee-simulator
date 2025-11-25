#include "DrinkFactory.hpp"

Drink* DrinkFactory::create(const std::string& type) {
    if (type == "pumpkin") return new PumpkinLatte();
    return nullptr;
}
