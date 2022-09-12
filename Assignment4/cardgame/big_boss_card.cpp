#include <iostream>
#include <map>
#include <queue>
#include "player.h"
#include "card.h"
#include "big_boss_card.h"

void BigBossCard::effect(Card& opponentCard, Player& player, Player& opponent)
{
    map <int, int> A, D;
    queue <int> deck_queue;

    for(int j = 0; j < player.deck.size(); j++)
    {
        player.deck[j].attack += opponentCard.attack;
        player.deck[j].defense += opponentCard.defense;
        A[player.deck[j].attack] = 1;
        A[player.deck[j].defense] = 1;
    }

    for(int k = 0; k < opponent.deck.size(); k++)
    {
        if(A[opponent.deck[k].attack])
        {
            deck_queue.push(k);
        }
        if (D[opponent.deck[k].defense])
        {
            deck_queue.push(k);
        }
    }

    while(deck_queue.size())
    {
        opponent.deck.erase(opponent.deck.begin() + deck_queue.front());
        deck_queue.pop();
    }
}

BigBossCard::BigBossCard(std::string name, int attack, int defense) : Card(name, attack, defense) {

}


