#include <stdio.h>

#include "deck/deck.h"


int main(){

	int debug = 0;

	char selected[2];
	printf("Programm Started...\n");

	printf("Shuffle Deck? [y/n]");
	scanf("%1s" ,selected);
	
	if(debug){
		// Results in the same adress, because arrays variable holds a pointer to the first item.
		printf("%p\n", &selected[0]);
		printf("%p\n", selected);
	}

	if (selected[0] == 'y')
	{
		printf("Shuffling deck..\n");
		struct PokerDeck deck_ = constructPokerDeck();

		printf("First Card: %s%c\n",Color_To_String[deck_.deck[1].color], Value_To_AutString[deck_.deck[1].value]);


	}
	else
	{
		printf("You are cheating!\n");
	}

}
