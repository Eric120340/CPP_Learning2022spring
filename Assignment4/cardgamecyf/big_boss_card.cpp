#include "big_boss_card.h"

void effect(Card& opponentCard, Player& player, Player& opponent)
{
    //add attack and defense of the opponent's card to all card's in the player's deck
    for (int i = 0; i < player.deck.size(); i++)
    {
        player.deck[i].attack += opponentCard.attack;
        player.deck[i].defense += opponentCard.attack;
    }
    //remove all the card's in the opponent's deck that share an attack or defense value of the opponent's card
    for (int i = 0; i < opponent.deck.size(); i++)
    {
        if (opponent.deck[i].attack == opponentCard.attack ||
            opponent.deck[i].defense == opponentCard.defense)
        {
            opponent.deck.erase(opponent.deck.begin() + i);
        }
        
    }
}