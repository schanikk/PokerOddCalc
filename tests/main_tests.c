#include "game/deck_test.h"


int main(){
    test_comparePokerCard();
    test_constructPokerCard();

    test_comparePokerDeck();
    test_constructPokerDeck();

    test_shuffleDeck();
    test_drawCard();
}