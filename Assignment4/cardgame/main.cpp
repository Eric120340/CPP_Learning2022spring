#include <iostream>
#include <vector>

#include "card.h"
#include "exchange_card.h"
#include "player.h"
#include "big_boss_card.h"

using namespace std;

int main() {
    Card card_o ("card", 1, 2);
    ExchangeCard excard_o("excard", 3, 4);
    BigBossCard bigcard_o("bigcard", 5, 6);
    Card *card = &card_o;
    Card *excard = &excard_o;
    Card *bigcard = &bigcard_o;
    std::vector<Card> deck = {*card, *card, *card, *card, *card, *card};
    std::vector<Card> opponentDeck = {*excard, *excard, *excard, *excard, *excard, *excard};
    std::vector<Card> bigBossDeck = {*bigcard, *bigcard, *bigcard, *bigcard, *bigcard, *bigcard, *bigcard};
    Player player = Player(deck, "John");
    Player opponent = Player(opponentDeck, "Alice");
    Player opponent2 = Player(bigBossDeck, "Bob");
    excard->effect(opponent.hand[0], player, opponent);
    bigcard->effect(opponent2.hand[1], player, opponent2);
    cout << opponent.deck.size() << endl;
    cout << player.deck.size() << endl;
    cout << opponent2.deck.size() << endl;
    player.displayHand();
    opponent.displayHand();
    opponent2.displayHand();
    cout << player.deck[0] << endl;
}