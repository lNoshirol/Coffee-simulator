#include "DrinkFactory.hpp"
#include <vector>

std::vector<Drink*> DrinkFactory::create(const std::string& type) {
    std::vector<Drink*> DrinkLiist = { 
        new PumpkinLatte(), 
        new Tea(), 
        new Coffee(), 
        new CiaoKombucha(), 
        new BubbleTea(), 
        new HotChocolate(),
        new Chocolatte(),
        //new VoidCoffee(),
        //new GamerCoffee(), 
        //new Prozaczopixane(), 
        //new WarCoffee(), 
        //new IQCoffee(),
        //new CoffeeForBeach(),
        //new ClashRoyalCoffee(),
        //new McdoCoffee(),
        //new PiscineCoffee()
    };
    return DrinkLiist;
}
