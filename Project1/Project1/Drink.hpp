#pragma once
#include <vector>
#include <string>

class Drink {
public:
    virtual ~Drink() = default;
    //virtual std::string getId() const = 0;
    //virtual std::string getName() const = 0;
    virtual std::vector<std::string> getSteps() const = 0;
    virtual int getPrice() const = 0;
    virtual std::string getName() const = 0;
};

class PumpkinLatte : public Drink {
public:
    std::vector<std::string> getSteps() const override {
        return { "cafe", "lait", "epices", "pumpkin" };
    }

    int getPrice() const override {
        return 5;
    }

    std::string getName() const override 
    {
        return "Pumkin Latte";
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

    std::string getName() const override
    {
        return "Tea";
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

    std::string getName() const override
    {
        return "Void Coffee";
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

    std::string getName() const override
    {
        return "Coffee";
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

    std::string getName() const override
    {
        return "Ciao Kombucha";
    }
};

class BubbleTea : public Drink {
public:
    std::vector<std::string> getSteps() const override {
        return { "perles de tapioca", "the", "lait", "sucre" };
    }

    int getPrice() const override {
        return 10;
    }

    std::string getName() const override
    {
        return "Bubble Tea";
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

    std::string getName() const override
    {
        return "Hot CHocolate";
    }
};

class GamerCoffee : public Drink {
public:
    std::vector<std::string> getSteps() const override {
        return { "Processeur itel core i15", "rtx 5090 max Q", "RAM 32Go ddr4", "SSD crucial 4To", "license windows familiale" };
    }

    int getPrice() const override {
        return 3469;
    }

    std::string getName() const override
    {
        return "Gamer Coffee";
    }
};

class Prozaczopixane : public Drink {
public:
    std::vector<std::string> getSteps() const override {
        return { "Antidépresseur", "anxiolitique", "Calmant", "Somnifère", "ca suffit pas le dolipranne" };
    }

    int getPrice() const override {
        return 99;
    }

    std::string getName() const override
    {
        return "Prozaczopixane";
    }
};

class WarCoffee : public Drink {
public:
    std::vector<std::string> getSteps() const override {
        return { "Poudre", "Ak47", "Char de combat MBT t80bvm", "Missile Javelin", "Munitions" };
    }

    int getPrice() const override {
        return 487938143;
    }

    std::string getName() const override
    {
        return "WarCoffee";
    }
};

class IQCoffee : public Drink {
public:
    std::vector<std::string> getSteps() const override {
        return { "Lyta", "Nathan", "Steve Jobs", "Albert Eiinstein", "Dictionnaire Larousse edition 2015 version de poche"};
    }

    int getPrice() const override {
        return 36780015;
    }

    std::string getName() const override
    {
        return "IQ coffee";
    }
};

class CoffeeForBeach : public Drink {
public:
    std::vector<std::string> getSteps() const override {
        return { "Sable fin de la tranche sur mer ramassé à 21h19 et 45 secondes à 5 mètres des vagues lors d'une marée descendante", "sel"};
    }

    int getPrice() const override {
        return 56;
    }

    std::string getName() const override
    {
        return "CoffeeForBeach";
    }
};

class ClashRoyalCoffee : public Drink {
public:
    std::vector<std::string> getSteps() const override {
        return { "Mega Chevalier", "PEKKA", "Fabtome raoyal", "Tour du roi", "Zappy", "l'emote heheheha"};
    }

    int getPrice() const override {
        return 400;
    }

    std::string getName() const override
    {
        return "ClashRoyalCoffee";
    }
};

class McdoCoffee : public Drink {
public:
    std::vector<std::string> getSteps() const override {
        return { "Nuggets", "grande frite", "McFlurry", "Borne de commande McDo"};
    }

    int getPrice() const override {
        return 786;
    }

    std::string getName() const override
    {
        return "McdoCoffee";
    }
};

class PiscineCoffee : public Drink {
public:
    std::vector<std::string> getSteps() const override {
        return { "Chlore", "5000 metre cube d'eau", "Centre aquatique olympique de paris", "le pipi des CP"};
    }

    int getPrice() const override {
        return 487000;
    }

    std::string getName() const override
    {
        return "Piscine Coffee";
    }
};