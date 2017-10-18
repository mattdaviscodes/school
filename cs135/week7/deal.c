// Deal hand of cards using MultiDimensional array

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SUITS 4
#define NUM_RANKS 13
#define CARD_DEALT_IDENTIFIER X

int main(void)
{

    char suits[4] = {'c', 'd', 'h', 's'};
    char deck[NUM_SUITS][NUM_RANKS];

    // Populate deck
    for (int i = 0; i < NUM_SUITS; i++) {
        deck[i] = {'2', '3', '4', '5', '6', '7', '8', '9', 't', 'j', 'q', 'k', 'a'}
    }

    for (int i = 0; i < 4; i++) {
        printf("%c\n", suits[i]);
    }

    return 0;
}
