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

static const char* InputToUserAction[9] = {"reset board", "reset player", "show info", "set card", "set card [0-9]", "set board", "delete", "delete player", "delete board hand"};	// This List must match UserActions

int getUserActionIndex(char* input){
	int index;
	for (int i = 0; i < sizeof(InputToUserAction); i++){
		if(InputToUserAction[i] == input){
			index = i;
		}

	};
	return index;
};

enum UserAction getUserAction(char* input){
	enum UserAction user_action;
	// ToDo: Choosing Enum by Integer Representation?;
	//
	// Best way to build own commands?
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
