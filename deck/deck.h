#ifndef DECK_H
#define DECK_H
#define REGULARDECKSIZE  52
#define SHORTDECKSIZE 32
	

	// Should Color & Value be inside deck.c? Because it is only used internaly? 
	enum Color {
	
		DIAMONDS = 0,
		HEART,
		SPADES,
		CLUBS,
	};

	extern char *Color_To_String[]; // Declares an Array of Pointers. Where each Pointers is an array pointer

	

	enum Value {

		ACE=1,
		TWO,
		THREE,
		FOUR,
		FIVE,
		SIX,
		SEVEN,
		EIGHT,
		NINE,
		TEN,
		JACK,
		QUEN,
		KING,
	};
	
	extern char Value_To_AutString[];
	extern char *Value_To_String[];

	struct PokerCard {

		enum Value value;
		enum Color color;
	};

	struct PokerDeck{
		struct PokerCard deck[REGULARDECKSIZE];
	};

	void shuffleDeck(struct PokerCard *deck);
	void getAllCards(struct PokerCard *deck);
	struct PokerDeck constructPokerDeck();



#endif
