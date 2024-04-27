#ifndef DECK_H
#define DECK_H
#define REGULARDECKSIZE  52
#define SHORTDECKSIZE 32
	
	extern char *Color_To_String[]; // Declares an Array of Pointers. Where each Pointers is an array pointer
	extern char Value_To_AutString[];
	extern char *Value_To_String[];

	// Should Color & Value be inside deck.c? Because it is only used internaly? 
	enum Suit {
	
		DIAMONDS = 0,
		HEART,
		SPADES,
		CLUBS,
	};

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

	struct PokerCard {
        enum Suit suit;
		enum Value value;
	};

    enum PokerType{
        OMAHA,
        SHORTDECK,
        HOLDEM,
    };

	struct PokerDeck{
		struct PokerCard deck[REGULARDECKSIZE];
        enum PokerType deckType;
        int deck_size;
        int topOfDeck;
	};

    struct PokerCard constructPokerCard(enum Suit suit, enum Value value);
    struct PokerDeck constructPokerDeck(enum PokerType type);
    struct PokerCard* drawCard(struct PokerDeck *deck);
	
	void shuffleDeck(struct PokerCard *deck);
	void getAllCards(struct PokerCard *deck, enum PokerType type);

#endif
