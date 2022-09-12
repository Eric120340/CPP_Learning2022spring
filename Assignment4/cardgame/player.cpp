#include <iostream>
#include <vector>
#include "card.h"
#include "player.h"

using namespace std;

Player::Player(std::vector<Card>& deck, std::string name)
{
    this->name = name;
    this->deck = deck;
    //A hand of cards means five cards???
    for (int i = 1; i <= 5; i++)
    {
        this->draw();
    }
}

void Player::draw()
{
    Card PlayerCard = deck.at(deck.size() - 1);
    //this->hand.at(deck.size()) = deck.at(deck.size()-1);
    deck.pop_back();

    //hand.push_back(PlayerCard);
    hand.emplace_back(PlayerCard);  //New way
}

Card Player::play(int index)
{
    Card PlayedCard = hand[index];
    this->hand.erase(hand.begin() + index);
    return PlayedCard;
}

void Player::displayHand()
{
    for (int i = 0; i < hand.size(); i++)
    {
        cout << hand[i].name << " " << hand[i].attack << " " << hand[i].defense << endl;
    }

}
