#pragma once
#include <string>

enum class Ingredient {
    Cafe,
    Lait,
    Epices,
    Chocolat,
    Chantilly,
    Citrouille,
    Eau,
    The,
    Sucre,
    Kombucha,
    Tapioca,
};

inline std::string ingredientToString(Ingredient ing) {
    switch (ing) {
    case Ingredient::Cafe: return "cafe";
    case Ingredient::Lait: return "lait";
    case Ingredient::Epices: return "epices";
    case Ingredient::Chocolat: return "chocolat";
    case Ingredient::Chantilly: return "chantilly";
    case Ingredient::Citrouille: return "citrouille";
    case Ingredient::Eau: return "eau";
    case Ingredient::The: return "the";
    case Ingredient::Sucre: return "sucre";
    case Ingredient::Kombucha: return "kombucha";
    case Ingredient::Tapioca: return "tapioca";
    }
    return "";
}

inline bool stringToIngredient(const std::string& s, Ingredient& out) {

    if (s == "cafe") { out = Ingredient::Cafe; return true; }
    if (s == "lait") { out = Ingredient::Lait; return true; }
    if (s == "epices") { out = Ingredient::Epices; return true; }
    if (s == "chocolat") { out = Ingredient::Chocolat; return true; }
    if (s == "chantilly") { out = Ingredient::Chantilly; return true; }
    if (s == "citrouille") { out = Ingredient::Citrouille; return true; }
    if (s == "eau") { out = Ingredient::Eau; return true; }
    if (s == "the") { out = Ingredient::The; return true; }
    if (s == "sucre") { out = Ingredient::Sucre; return true; }
    if (s == "kombucha") { out = Ingredient::Kombucha; return true; }
    if (s == "tapioca") { out = Ingredient::Tapioca; return true; }

    return false;
}

inline int ingredientPrice(Ingredient ing) {
    switch (ing) {
    case Ingredient::Cafe: return 2;
    case Ingredient::Lait: return 1;
    case Ingredient::Epices: return 2;
    case Ingredient::Chocolat: return 1;
    case Ingredient::Chantilly: return 2;
    case Ingredient::Citrouille: return 3;
    case Ingredient::Eau: return 0;
    case Ingredient::The: return 1;
    case Ingredient::Sucre: return 1;
    case Ingredient::Kombucha: return 8;
    case Ingredient::Tapioca: return 5;
    }
    return 0;
}
