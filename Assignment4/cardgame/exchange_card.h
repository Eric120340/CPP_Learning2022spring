#include <iostream>
#include "card.h"

using namespace std;

class ExchangeCard : public Card
{
public:
    ExchangeCard(std::string name, int attack, int defense);
    void effect(Card& opponentCard, Player& player, Player& opponent);
};
