#include <string.h>
#include "game.h"
#include "deck.h"

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
	if (strlen(name) > MAXNAMELENGTH){
		return;
	}
	strcpy(player.name, name);

	return player;
};

int compare_player(const void* obj1, const void* obj2){
    const struct Player* p1 = obj1;
    const struct Player* p2 = obj2;
    int diff;

    diff = p1->playerID - p2->playerID;
    if(diff != 0){
        return diff;
    }
    diff = strcmp(p1->name, p2->name);
    if(diff != 0){
        return diff;
    }

    return 0;
};

struct GameTable{
	struct PokerDeck tableDeck;

	int tableID;
	struct Player players_[8];

	float currPot;
	struct PokerCard currCards[5];
};


void setFlop(struct GameTable *table, struct PokerCard *cards){
    table->currCards[0] = cards[0];
    table->currCards[1] = cards[0];
    table->currCards[2] = cards[0];
};

void setTurn(struct GameTable *table, struct PokerCard card){
    table->currCards[3] = card;
};

void setRiver(struct GameTable *table, struct PokerCard card){
    table->currCards[4] = card;
};

void SetPlayerHand(struct GameTable *table,struct Player player, struct PokerCard *cards){


    int tableLength=(sizeof(table->players_) / sizeof(table->players_[0]));

    for(int i = 0; i < tableLength; i++){

    };
};

void resetPlayer(struct Player *player){
    if(player == NULL){
        return;
    }
    memset(player->currHand, 0, sizeof(player->currHand));
};

void resetBoard(struct GameTable *table){
    if(table == NULL){
        return;
    };
    memset(table->currCards, 0, sizeof(table->currCards));
};

void resetTable(struct GameTable *table){

    if(table == NULL){
        return;
    }

    resetBoard(table);

    int tableLength = (sizeof(table->players_) / sizeof(table->players_[0]));
    for(int i = 0; i < tableLength; i++){
        resetPlayer(&table->players_[i]);
    };
};

enum Position{
    BIG_BLIND,
    UNDER_THE_GUN,
    UNDER_THE_GUN_1,
    LOJACK,
    HIJACK,
    CUTOFF,
    DEALER,
    SMALL_BLIND,
};
// char <identifier>[ROW][COL] <=> char *<identifier>[ROW]
//
// Why? char* means that we create a variable holding char pointers. <identifier>[ROW] means we want to create an array of char pointers.
//
//
// NOT UNDERSTANDING: Do we have to declare that the char* pointers within the array are also arrays? I know that Arrays variables holds the Pointer to the first Element but how do we know that we have an array?
const char *Pokertype_To_String[3] = {"Pot Limit Omaha", "No Limit HoldEm", "Short Deck"};
const char *Pokertype_To_Abreviation[3] = {"PLO", "NL Hold'em", "ShortDeck"};
const int Pokertype_To_Number_Of_Cards[3] = {4, 2, 2};

const int TableSize_To_Number_Of_Players[2] = {6,8};
const enum Position *TableSize_To_Seats[2] = {{BIG_BLIND, LOJACK, HIJACK, CUTOFF,DEALER, SMALL_BLIND}, {BIG_BLIND, UNDER_THE_GUN, UNDER_THE_GUN_1, LOJACK, HIJACK, CUTOFF, DEALER, SMALL_BLIND}};

const char *Position_To_Abbrev[8] = {"BB", "UTG", "UTG+1", "LJ", "HJ", "CO", "D", "SB"};
const char *Position_To_String[8] = {"BigBlind", "Under The Gun", "Under The Gun+1", "LoJack", "HighJack", "CUTOFF", "Dealer", "SmallBlind"};

struct Round{
	int level;
	float smallBlind;
	float bigBlind;

};

struct Round constructFirstRound(float sb, float bb){
	struct Round newRound;

	newRound.smallBlind = sb;
	newRound.bigBlind = bb;
	newRound.level = 1;

	return newRound;
};

struct GameState{
	struct GameTable tables[10];
	enum PokerType pokertype;
	struct Round round;
	struct Player *players;
};

// " <Class>-><Field> " <=> "(*<Class>).<Field> SAME SAME

void advanceRound(struct GameState *state){
	state->round.bigBlind*=2; // " -> " Arrow Operator derefenreces before acessing struct fields
	state->round.smallBlind*=2;
	state->round.level+=1;
};