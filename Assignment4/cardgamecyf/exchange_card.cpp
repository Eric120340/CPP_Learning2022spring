#include "exchange_card.h"

void effect(Card& opponentCard, Player& player, Player& opponent)
{
    //Exchange the values of attack power and defense power of the opponent played card
    
    //regular way
    /* int Temp_Change;
    Temp_Change = opponentCard.attack;
    opponentCard.attack = opponentCard.defense;
    opponentCard.defense = Temp_Change; */

    //Simple way
    swap(opponentCard.attack,opponentCard.defense);
}
