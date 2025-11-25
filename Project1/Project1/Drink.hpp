#pragma once
#include <vector>
#include <string>

class Drink {
public:
    virtual ~Drink() = default;
    virtual std::vector<std::string> getSteps() const = 0;
};

class PumpkinLatte : public Drink {
public:
    std::vector<std::string> getSteps() const override {
        return { "cafe", "lait", "epices", "pumpkin" };
    }
};

class Tea : public Drink {
public:
    std::vector<std::string> getSteps() const override {
        return { "eau", "herbe" };
    }
};

class VoidCoffe : public Drink {
public:
    std::vector<std::string> getSteps() const override {
        return { "" };
    }
};

/*class VoidCoffe : public Drink {
public:
    std::vector<std::string> getSteps() const override {
        return { "" };
    }
};*/
