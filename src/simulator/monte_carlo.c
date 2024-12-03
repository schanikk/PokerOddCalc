#include <stdio.h>
#include <stdlib.h>
#include "deck.h"
#include "game.h"

// Function to simulate a single hand and determine the winner
int simulateHand(struct PokerDeck *deck, struct Player *player) {
    // Shuffle the deck
    shuffleDeck(deck->deck);

    // Draw cards for players
    struct PokerCard player1_hand[OMAHAHANDSIZE];
    struct PokerCard player2_hand[OMAHAHANDSIZE];

    player1_hand[0] = drawCardRandomCard(deck);
    player1_hand[1] = drawCardRandomCard(deck);
    player1_hand[2] = drawCardRandomCard(deck);

    // Simulate flop, turn, and river cards
    struct PokerCard flop_cards[3];
    for (int i = 0; i < 3; i++) {
        flop_cards[i] = drawCard(deck);
    }

    struct PokerCard turn_card = drawCard(deck);
    struct PokerCard river_card = drawCard(deck);

    // Set board cards
    player1_hand[3] = flop_cards[0];
    player1_hand[4] = flop_cards[1];
    player2_hand[3] = flop_cards[0];
    player2_hand[4] = flop_cards[1];

    // Check for flush, straight, etc.
    int player1_rank = evaluateHand(player1_hand);
    int player2_rank = evaluateHand(player2_hand);

    return player1_rank > player2_rank ? 1 : (player1_rank < player2_rank ? -1 : 0);
}

// Function to simulate multiple hands and calculate equity
void mcSimulation(struct GameTable *table, float* equity) {
    int simCount = 10000; // Number of simulations
    int wins[8] = {0}; // Array to store wins for each player

    for (int i = 0; i < simCount; i++) {
        struct PokerDeck deck = constructPokerDeck(table->tableDeck.deckType);

        // Draw cards for all players
        for (int j = 0; j < table->tableDeck.numPlayers; j++) {
            struct PokerCard player_hand[OMAHAHANDSIZE];
            for (int k = 0; k < OMAHAHANDSIZE; k++) {
                player_hand[k] = drawCardRandomCard(deck);
            }

            // Simulate flop, turn, and river cards
            struct PokerCard flop_cards[3];
            for (int l = 0; l < 3; l++) {
                flop_cards[l] = drawCard(deck);
            }

            struct PokerCard turn_card = drawCard(deck);
            struct PokerCard river_card = drawCard(deck);

            // Set board cards
            for (int k = 0; k < OMAHAHANDSIZE; k++) {
                player_hand[k] = flop_cards[0];
            }
            player_hand[3] = flop_cards[1];
            player_hand[4] = flop_cards[2];

            // Check for flush, straight, etc.
            int player_rank = evaluateHand(player_hand);
            wins[table->players_[j].playerID] += (player_rank > 0 ? 1 : -1);
        }

        shuffleDeck(deck.deck); // Shuffle the deck for the next simulation
    }

    // Calculate equity for each player
    float totalWins = 0.0;
    for (int j = 0; j < table->tableDeck.numPlayers; j++) {
        totalWins += wins[j];
    }
    for (int j = 0; j < table->tableDeck.numPlayers; j++) {
        equity[j] = ((float)wins[j] / totalWins) * 100;
        printf("Player %d Equity: %.2f%%\n", table->players_[j].playerID, equity[j]);
    }
}

// Example function to run the Monte Carlo Simulation
void runMonteCarloSimulation(struct GameTable *table) {
    float equity[8];
    memset(equity, 0, sizeof(equity));
    mcSimulation(table, equity);
}