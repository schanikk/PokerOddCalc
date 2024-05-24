#include <stdlib.h>
#include <stdio.h>
#include "deck.h"


const char *Color_To_String[4] = {"Diamonds", "Hearth", "Spades", "Clubs"}; // Declares an Array of Pointers. Where each Pointer are an array pointer
const char *Value_To_String[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
const char Value_To_AutString[13] = {'A', '2', '3' , '4', '5', '6', '7', '9', 'T', 'J','Q','K'};

/*
 * Get Almost Uniform random number; (  https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)Randomization.html)
 *
 * 
 * */
int getRandomInteger(int n){

	int limit;
	int r;

	limit = RAND_MAX - (RAND_MAX % n);

	while((r = rand()) >= limit);

	return r % n;

}

/*
 * Using Fisher-Yates shuffle ( https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle )
 */
void shuffleDeck(struct PokerCard *deck){
	// @FixBug: Segmentation Fault when entering here
	//
	/*
	 * Using Fisher-Yates shuffle ( https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle )
	 */

    if (deck == NULL){
        fprintf(stderr, "Error: deck is NULL\n");
        return;
    }

	srand ( 123 );

	for(int i = 0; i<REGULARDECKSIZE-2; i++){
		int j = getRandomInteger(REGULARDECKSIZE);
		struct PokerCard temp = deck[i];
		deck[i] = deck[j];
		deck[j] = temp;

	}

};

struct PokerCard *drawCardRandomCard(struct PokerCard *deck){
    if (deck == NULL){
        fprintf(stderr, "Error: deck is NULL\n");
        return NULL;
    }
	return &deck[getRandomInteger(REGULARDECKSIZE)];
};

struct PokerCard *drawCard(struct PokerDeck *deck){

    if (deck == NULL){
        fprintf(stderr, "Error: deck is NULL\n");
        return NULL;
    };
    if (deck->topOfDeck >= deck->deck_size){
        fprintf(stderr, "Error: Deck is Empty\n");
        return NULL;
    };

    struct PokerCard *card = &(deck->deck[deck->topOfDeck]);
    deck->topOfDeck +=1;

	return card;
};

struct PokerCard constructPokerCard(enum Suit suit, enum Value value){
    struct PokerCard card = {suit, value};
    return card;
};

// @ToDo: Implement Dynamic Allocation (OMAHA vs ShortDeck)
struct PokerDeck constructPokerDeck(enum PokerType type){
	struct PokerDeck deck_;
    deck_.deckType = type;
    deck_.deck_size = REGULARDECKSIZE;
    deck_.topOfDeck = 0;

    int pos = 0;
    for(enum Suit i = DIAMONDS; i <= CLUBS; i++ ){
        for (enum Value k = ACE; k <= KING; k++){

            struct PokerCard temp_ = constructPokerCard(i, k);
            *(deck_.deck+pos) = temp_;
            pos+=1;
        }
    }

	return deck_;
};
