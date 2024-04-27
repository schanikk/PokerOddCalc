#include <assert.h>
#include "../../src/game/deck.h"

int comparePokerCard(void* obj1, void* obj2){
    const struct PokerCard* card1 = obj1;
    const struct PokerCard* card2 = obj2;
    int diff;

    if((diff = card1->value - card2->value) != 0){
        return diff;
    }

    if((diff = card1->suit-card2->suit) != 0){
        return diff;
    }

    return 0;
};

void test_comparePokerCard(){
    const struct PokerCard card = {DIAMONDS, ACE};

    const struct PokerCard test_card = {DIAMONDS, ACE};
    const struct PokerCard wrong_test_card = {DIAMONDS, TWO};

    assert((card.suit == test_card.suit && card.value == test_card.value) && comparePokerCard(&card, &test_card) == 0 && "Assertion Failed");
    assert((card.suit == wrong_test_card.suit && card.value != wrong_test_card.value) && comparePokerCard(&card, &wrong_test_card) != 0 && "Assertion Failed");

};

void test_constructPokerCard(){
    struct PokerCard card = {DIAMONDS, ACE};

    struct PokerCard test_card = constructPokerCard(DIAMONDS, ACE);

    assert(comparePokerCard(&card, &test_card) == 0 && "Assertion Failed");
};

int comparePokerDeck(void* obj1, void* obj2, size_t n){
    struct PokerDeck* deck1 = obj1;
    struct PokerDeck* deck2 = obj2;

    int diff;
    if((diff = deck1->deckType - deck2->deckType) != 0){
        return diff;
    }

    for(size_t i = 0; i < n; i++) {
        struct PokerCard c1 = deck1->deck[i];
        struct PokerCard c2 = deck2->deck[i];

        if ((diff = comparePokerCard(&c1, &c2)) != 0) {
            return diff;
        }
    }
    return 0;
};

void test_comparePokerDeck(){
    struct PokerDeck deck1 = constructPokerDeck(OMAHA);
    struct PokerDeck deck1_equal = constructPokerDeck(OMAHA);
    struct PokerDeck deck1_unequal_type = constructPokerDeck(HOLDEM);
    // Change two Cards;
    struct PokerDeck deck1_unequal_deck = constructPokerDeck(OMAHA);
    struct PokerCard temp = deck1_unequal_deck.deck[5];
    deck1_unequal_deck.deck[5] = deck1_unequal_deck.deck[3];
    deck1_unequal_deck.deck[3] = temp;

    assert((comparePokerDeck(&deck1, &deck1_equal, deck1.deck_size) == 0) && "Assertion Failed");
    assert((comparePokerDeck(&deck1, &deck1_unequal_deck, deck1.deck_size) != 0) && "Assertion Failed");
    assert((comparePokerDeck(&deck1, &deck1_unequal_type, deck1.deck_size) != 0) && "Assertion Failed");
};


// @ToDo: Implement Further Testing
void test_constructPokerDeck(){
    struct PokerDeck deck;
    deck.deck_size = 52;
    deck.deckType = OMAHA;

    int pos = 0;
    for(enum Suit i = DIAMONDS; i <= CLUBS; i++ ){
        for (enum Value k = ACE; k <= KING; k++){

            struct PokerCard temp_ = constructPokerCard(i, k);
            *(deck.deck+pos) = temp_;
            pos+=1;
        }
    }

    struct PokerDeck testDeck = constructPokerDeck(OMAHA);

    assert(comparePokerDeck(&deck, &testDeck, deck.deck_size) == 0 && "Assertion Failed");
};

void test_shuffleDeck(){

    struct PokerDeck deck = constructPokerDeck(OMAHA);

    struct PokerCard first_card = deck.deck[0];
    struct PokerCard last_card = deck.deck[51];

    shuffleDeck(deck.deck);

    assert((comparePokerCard(&first_card, &deck.deck[0]) != 0) && "Assertion Failed");
    assert((comparePokerCard(&last_card, &deck.deck[0]) != 0) && "Assertion Failed");

};


void test_drawCard(){

    struct PokerDeck deck = constructPokerDeck(OMAHA);
    struct PokerCard firstDrawnCard = deck.deck[0];
    struct PokerCard secondDrawnCard = deck.deck[1];
    struct PokerCard thirdDrawnCard = deck.deck[2];

    assert((comparePokerCard(&firstDrawnCard, drawCard(&deck)) == 0) && "Assertion Failed");
    assert((comparePokerCard(&secondDrawnCard, drawCard(&deck)) == 0) && "Assertion Failed");
    assert((comparePokerCard(&thirdDrawnCard, drawCard(&deck)) == 0) && "Assertion Failed");



};