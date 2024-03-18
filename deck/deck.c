#include "deck.h"

char *Color_To_String[4] = {"Diamonds", "Hearth", "Spades", "Clubs"}; // Declares an Array of Pointers. Where each Pointers is an array pointer

char *Value_To_String[14] = {"Ace", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
char Value_To_AutString[14] = {'A', '1', '2', '3' , '4', '5', '6', '7', '9', 'T', 'J','Q','K'};

void getAllCards(struct PokerCard* deck_){
	
	// Iterating over Enum possible using simple For Loop (Due that by default Enums receives Values starting from 0, incrementing)
	// Order of declaration matters!

	int pos = 0;
	for(int i = DIAMONDS; i <= CLUBS; i++ ){
		for (int k = ACE; k <= KING; k++){

			struct PokerCard temp_;
			temp_.value = k;
			temp_.color = i;
			*(deck_+pos) = temp_;
			pos+=1;
		}
	}

};

struct PokerDeck constructPokerDeck(){
	
	struct PokerDeck deck_;
	getAllCards(deck_.deck);

	return deck_;
};
