#include <stdio.h>

#include "deck/deck.h"


int main(){

	int debug = 0;

	char selected[1];
	printf("Programm Started...\n");

	printf("Shuffle Deck? [y/n]");
	scanf("%1s" ,selected);
	
	if(debug==0){
		// Results in the same adress, because arrays variable holds a pointer to the first item.
		printf("%p\n", &selected[0]);
		printf("%p\n", selected);
	}

	if (selected[0] == 'y')
	{

		printf("First Five Cards Before Shuffling\n");
		struct PokerDeck deck_ = constructPokerDeck();

		for(int i = 0; i < 5; i++){

			printf("%i. Card: %s%c\n",i, Color_To_String[deck_.deck[i].color], Value_To_AutString[deck_.deck[i].value]);

		}

		printf("Shuffling deck..\n");
		shuffleDeck(deck_.deck);
		
		printf("First Five Cards After Shuffling\n");
		for(int i = 0; i < 5; i++){

			printf("%i. Card: %s%c\n",i, Color_To_String[deck_.deck[i].color], Value_To_AutString[deck_.deck[i].value]);

		}


	}
	else
	{
		printf("You are cheating!\n");
	}

}
