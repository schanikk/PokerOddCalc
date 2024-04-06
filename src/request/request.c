enum UserAction {
	RESET_BOARD,
	PICK_PLAYER_HAND,
	SHOW_PLAYER_INFO,
	SET_CARD_BY_NUMBER,
	SET_CARD,
	SET_BOARD_HAND,
	DELTE_CARD,
	DELETE_PLAYER_HAND,
	DELET_BOARD_HAND,
};


// ToDo: Change to Hierarchical Commands (Group by First Hirarchy: Set, Remove, Show, Reset, Second: Entity( UTG, BB, SB, Flop,Turn, River))
static const char* InputToUserAction[9] = {"reset board", "reset player", "show info", "set card", "set card [0-9]", "set board", "delete", "delete player", "delete board hand"};	// This List must match UserActions

int getUserActionIndexByInput(*char input){
	int index;
	int arr_length = sizeof(input) / sizeof(input[0]);
	for (int i = 0; i < arr_length; i++){
		if(InputToUserAction[i] == input){
			index = i;
		}

	};
	return index;
};


char *Tokenize(char* input){

	char* tokens[];

	return tokens;
};

enum UserAction getUserActionByInput(char* input){
	enum UserAction user_action;
	// ToDo: Choosing Enum by Integer Representation?;
	//
	// Best way to build own commands?
	//
	// Parser + Lexer (But overkill) for now we do simple regex matching
	user_action = getUserAction(input);
	return user_action;
};

struct Request{
	enum UserAction action;
	char *arguments[25];
};

struct Request convertUserInput(char* input){
	enum UserAction user_action = getUserAction();
	struct Request user_request;
	
	// Convert Here
	//
	// Using Array for Mapping? Switch? Small Compiler?

	return user_request;
};
