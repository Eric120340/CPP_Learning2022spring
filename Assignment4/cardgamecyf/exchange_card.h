#include <iostream>
#include <vector>

#include "player.h"
#include "card.h"

using namespace std;

class ExchangeCard : public Card
{
public:
    ExchangeCard(/* args */);
    ExchangeCard(std::string, int attack, int defense);
    
    void effect(Card& opponentCard, Player& player, Player& opponent);
    ~ExchangeCard();
    
};

ExchangeCard::ExchangeCard(/* args */)
{
}

ExchangeCard::~ExchangeCard()
{
}
