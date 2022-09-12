#include <iostream>
#include <vector>

#include "player.h"
#include "card.h"

using namespace std;

class BigBossCard : public Card
{
public:
    BigBossCard(/* args */);
    BigBossCard(std::string, int attack, int defense);

    void effect(Card& opponentCard, Player& player, Player& opponent);
    ~BigBossCard();
    
};

BigBossCard::BigBossCard(/* args */)
{
}

BigBossCard::~BigBossCard()
{
}
