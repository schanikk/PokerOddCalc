#include <string.h>

#include "game.h"
#include "../deck/deck.h"

#define OMAHAHANDSIZE 4
#define HOLDEMHANDSIZE 2

#define SIXMAX 8
#define EIGHTMAX 6
#define MAXNAMELENGTH 25

struct Player{
	int playerID;
	char name[MAXNAMELENGTH];
	struct PokerCard currHand[OMAHAHANDSIZE];
	float currChips;	
};

struct Player createPlayer(int id, char *name){
	struct Player player;
	player.playerID = id;

	// Do not copy name if bufferoverflow
	if (sizeof(*name) > MAXNAMELENGTH){
		return player;
	}
	strcpy(player.name, name);

	return player;
};

struct GameTable{
	struct PokerDeck tableDeck;

	int tableID;
	struct Player players_[8];

	float currPot;
	struct PokerCard currCards[5];
};

enum PokerType{
	OMAHA,
	SHORTDECK,
	HOLDEM,
};

// char <identifier>[ROW][COL] <=> char *<identifier>[ROW]
//
// Why? char* means that we create a variable holding char pointers. <identifier>[ROW] means we want to create an array of char pointers.
//
//
// NOT UNDERSTANDING: Do we have to declare that the char* pointers within the array are also arrays? I know that Arrays variables holds the Pointer to the first Element but how do we know that we have an array?
const char *Pokertype_To_String[3] = {"Pot Limit Omaha", "No Limit HoldEm", "Short Deck"};

const char *Pokertype_To_Abreviation[3] = {"PLO", "NL Hold'em", "ShortDeck"};

struct Round{
	int level;
	float smallBlind;
	float bigBlind;

};

struct Round constructFirstRound(int sb, int bb){
	struct Round newRound;

	newRound.smallBlind = sb;
	newRound.bigBlind = bb;
	newRound.level = 1;

	return newRound;
};

struct GameSate{
	struct GameTable tables[10];
	enum PokerType pokertype;
	struct Round round;
	struct Player *players;
};

// " <Class>-><Field> " <=> "(*<Class>).<Field> SAME SAME

void advanceRound(struct Round *round_){
	round_->bigBlind*=2; // " -> " Arrow Operator derefenreces before acessing struct fields
	round_->smallBlind*=2;
	round_->level+=1;
};
