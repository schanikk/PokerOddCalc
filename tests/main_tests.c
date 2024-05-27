#include <stdio.h>
#include "game/deck_test.h"


void testDeckModule(){
    printf("Testing Deck Module...\n");

    // Tests Here
    test_comparePokerCard();
    test_constructPokerCard();
    test_comparePokerDeck();
    test_constructPokerDeck();
    test_drawCard();
    test_shuffleDeck();

    printf("Deck Module Passed\n");
};

void testGameModule(){
    printf("Testing Game Module...\n");

    // Tests Here
    void test_advanceState();
    void test_setFlop();
    void test_setTurn();
    void test_SetRiver();
    void test_SetPlayerHand();
    void test_resetPlayer();
    void test_resetBoard();
    void test_resetTable();

    void test_pokerTypeToString();
    void test_pokerTypeToAbreviation();
    void test_createPlayer();
    void test_comparePlayer();
    void test_constructFirstRound();
    void test_advanceRound();

    printf("Game Module Passed\n");

};

int main(){
    testDeckModule();
}