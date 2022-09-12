#include <iostream>
#include "card.h"

using namespace std;

Card::Card(std::string name, int attack, int defense)
{
    this->name = name;
    this->attack = attack;
    this->defense = defense;
}

double Card::power(Card opponentCard)
{
    double powerValue;
    powerValue = (this->attack) - (opponentCard.defense) / 2;
    return max((double)0,powerValue);
}

void Card::effect(Card& opponentCard, Player& player, Player& opponent)
{
    //Default mode: no effect, TODO nothing
}

std::ostream& operator<<(std::ostream& os, const Card& card)
{
    os << "<" << card.name << ">" << " " << "<" << card.attack << ">" << " " << "<" << card.defense << ">";
    return os;
}
