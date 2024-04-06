#ifndef GAME_H
#define GAME_H
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

	enum Position{
		BIG_BLIND,
		SMALL_BLIND,
		DEALER,
		UTG1,
		UTG2,
		UTG3,
	};

#endif
