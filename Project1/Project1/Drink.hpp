#pragma once
#include <vector>
#include <string>

class Drink {
public:
    virtual ~Drink() = default;
    virtual std::vector<std::string> getSteps() const = 0;
    virtual int getPrice() const = 0;
};

class PumpkinLatte : public Drink {
public:
    std::vector<std::string> getSteps() const override {
        return { "cafe", "lait", "epices", "pumpkin" };
    }

    int getPrice() const override {
        return 5;
    }
};

class Tea : public Drink {
public:
    std::vector<std::string> getSteps() const override {
        return { "eau", "herbe" };
    }

    int getPrice() const override {
        return 1;
    }
};

class VoidCoffee : public Drink {
public:
    std::vector<std::string> getSteps() const override {
        return { "" };
    }

    int getPrice() const override {
        return 2;
    }
};

class Coffee : public Drink {
public:
    std::vector<std::string> getSteps() const override {
        return { "cafe", "eau" };
    }

    int getPrice() const override {
        return 3;
    }
};

class CiaoKombucha : public Drink {
public:
    std::vector<std::string> getSteps() const override {
        return { "eau", "sucre", "the", "kombucha"};
    }

    int getPrice() const override {
        return 15;
    }
};

class BubbleTea : public Drink {
public:
    std::vector<std::string> getSteps() const override {
        return { "perle de tapioca", "the", "lait", "sucre" };
    }

    int getPrice() const override {
        return 10;
    }
};

class HotChocolate : public Drink {
public:
    std::vector<std::string> getSteps() const override {
        return { "lait", "chocolat", "sucre"};
    }

    int getPrice() const override {
        return 4;
    }
};
