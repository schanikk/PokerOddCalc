#include <stdlib.h>
#include "deck.h"

char *Color_To_String[4] = {"Diamonds", "Hearth", "Spades", "Clubs"}; // Declares an Array of Pointers. Where each Pointers is an array pointer

char *Value_To_String[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
char Value_To_AutString[13] = {'A', '2', '3' , '4', '5', '6', '7', '9', 'T', 'J','Q','K'};



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
void shuffleDeck(struct PokerCard *deck){
	// @FixBug: Segmenation Fault when entering here 
	//
	/*
	 * Using Fisher-Yates shuffle ( https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle )
	 */
	srand ( 123 );
	for(int i = 0; i<REGULARDECKSIZE-2; i++){
		int j = getRandomInteger(REGULARDECKSIZE);
		struct PokerCard temp = deck[i];
		deck[i] = deck[j];
		deck[j] = temp;

	}

};

// @ToDo: Should return instead?
void getAllCards(struct PokerCard *deck){
	
	// Iterating over Enum possible using simple For Loop (Due that by default Enums receives Values starting from 0, incrementing)
	// Order of declaration matters!

	int pos = 0;
	for(int i = DIAMONDS; i <= CLUBS; i++ ){
		for (int k = ACE; k <= KING; k++){

			struct PokerCard temp_;
			temp_.value = k;
			temp_.color = i;
			*(deck+pos) = temp_;
			pos+=1;
		}
	}

};

struct PokerDeck constructPokerDeck(){

	struct PokerDeck deck_;
	// deck_.deck = getAllCards()?
	getAllCards(deck_.deck);

	return deck_;
};
