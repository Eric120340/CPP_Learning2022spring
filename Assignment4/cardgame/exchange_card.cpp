#include <iostream>
#include "exchange_card.h"

void ExchangeCard::effect(Card& opponentCard, Player& player, Player& opponent)
{
    swap(opponentCard.attack,opponentCard.defense);
}

ExchangeCard::ExchangeCard(std::string name, int attack, int defense) : Card(name, attack, defense){}