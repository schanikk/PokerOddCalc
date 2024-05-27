#ifndef REQUEST_H
#define REQUEST_H

#include "deck.h"

enum UserAction {
        RESET_BOARD,
        PICK_PLAYER_HAND,
        SHOW_PLAYER_INFO,
        SET_CARD_BY_NUMBER,
        SET_CARD,
        SET_BOARD_HAND,
        DELETE_CARD,
        DELETE_PLAYER_HAND,
        DELETE_BOARD_HAND,
    };


    // Interpreter Pattern
    typedef struct Context Context;

    typedef struct Expression {
        void (*interpret) (struct Expression*, Context*);
    } Expression;

    typedef struct setPlayerHand {
        Expression base;
        struct PokerCard *cards;
    } SetCardExpr;

    void interpretSetCard(struct Expression* expression,struct Context* context){
        SetCardExpr *setCard = (SetCardExpr*) context->expression;
    };

    typedef struct resetBoard {
        Expression base;
        struct PokerCard *cards;
    } ResetBoardExpr;

    void interpretResetBoard(struct Expression* expression, Context* context);

    typedef struct resetTable {
        Expression base;
        struct PokerCard *cards;
    } resetTableExpr;

    void interpretResetTable (struct Expression* expression, Context* context);

    typedef struct setFlop {
        Expression base;
        struct PokerCard *cards;
    } setFlopExpr;

    void interpretSetFlop(struct Expression* expression, Context* context);

    typedef struct setTurn {
        Expression base;
        struct PokerCard *cards;
    } setTurnExpr;

    void interpretSetTurn(struct Expression* expression, Context* context);

    typedef struct setRiver {
        Expression base;
        struct PokerCard *cards;
    } setRiverExpr;

    void interpretSetRiver(struct Expression* expression, Context* context);

#endif
