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

class GamerCoffe : public Drink {
public:
    std::vector<std::string> getSteps() const override {
        return { "Processeur itel core i15", "rtx 5090 max Q", "RAM 32Go ddr4", "SSD crucial 4To", "license windows", "K4met0"};
    }
};

class Prozaczopixane : public Drink {
public:
    std::vector<std::string> getSteps() const override {
        return { "Antidépresseur", "anxioliitique", "Calmant", "Somnifère", "ca suffit pas le dolipranne" };
    }
};

class WarCofe : public Drink {
public:
    std::vector<std::string> getSteps() const override {
        return { "Podre", "Ak47", "Char de combat MBT t80bvm", "Missile Javelin", "Munitions" };
    }
};

class ArmeeRusseCoffe : public Drink {
public:
    std::vector<std::string> getSteps() const override {
        return { "2s19m1", "t80bvm", "t14 armata", ""};
    }
};

/*class VoidCoffe : public Drink {
public:
    std::vector<std::string> getSteps() const override {
        return { "" };
    }
};*/
