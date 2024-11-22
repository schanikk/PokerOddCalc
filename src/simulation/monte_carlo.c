#include "monte_carlo.h"
#include <stdio.h> // NULL

#include <stdlib.h>
#include <assert.h> // For assertions
#include "../game/deck.h"
#include "../game/game.h"

// Helper function to check if a card is valid
int isValidCard(struct Card card) {
    // Check if rank and suit are within valid ranges
    return (card.rank >= 2 && card.rank <= 14 && card.suit >= 0 && card.suit <= 3);
}
int verify_table(struct GameTable *table) {
    // 1. Non-Null Table and Deck
    if (table == NULL || table->deck == NULL) {
        return -1; // Error: Null table or deck
    }

    // 2. Minimum Players
    if (table->num_players < 2) {
        return -2; // Error: Not enough players
    }

    // 3. Valid Player Hands
    for (int i = 0; i < table->num_players; i++) {
        if (table->players[i].hand == NULL || table->players[i].hand_size == 0) {
            return -3; // Error: Player with null or empty hand
        }
        for (int j = 0; j < table->players[i].hand_size; j++) {
            if (!isValidCard(table->players[i].hand[j])) {
                return -4; // Error: Invalid card in player's hand
            }
        }
    }


    // 4. Valid Board Cards
    int numBoardCards = table->board_size;
    if (numBoardCards != 0 && numBoardCards != 3 && numBoardCards != 4 && numBoardCards != 5) {
        return -5; // Error: Invalid number of board cards
    }
    for (int i = 0; i < numBoardCards; i++) {
        if (!isValidCard(table->board[i])) {
            return -6; // Error: Invalid board card
        }
    }

    // 5. Valid Pot Size
    if (table->pot < 0) {
        return -7; // Error: Negative pot size
    }


    // 6. No Duplicate Cards (Optional) - Implementation omitted for brevity, but highly recommended.

    // 7. Valid Deck Size (Optional) - Implementation depends on game logic.

    // 8. Current Player (Optional) - Implementation depends on game logic.


    // All checks passed
    return 0;
}



float monteCarloSimulation(struct GameTable *table, struct Player *player, int iterations) {
    if (table == NULL || player == NULL) return -1;

    if (verify_table((struct GameTable *) table)) return -1;

    int wins = 0;
    struct GameTable tempTable = *table; // Copy the original table to avoid modifying it
    struct Player tempPlayer = *player;


    for (int i = 0; i < iterations; i++) {



    }

}

int tableHasValidFlop(struct GameTable *table){

}

int simulate_table(struct GameTable *table, struct Player *player) {




}
