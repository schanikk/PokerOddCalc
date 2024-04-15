#ifndef GAME_H
#define GAME_H

    struct Player; // Represents Player
    struct Table; // Represent Table and Seats (UTG, BB,SB,D)
    struct TableState;
    struct Action;
    enum Position;

    void advanceState (struct TableState *state, struct Action action);

#endif
