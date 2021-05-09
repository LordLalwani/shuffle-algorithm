#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../header-files/rounds.h"

int main(int argc, char *argv[]) {
    unsigned long initialRounds = 0;
    unsigned long initialNumberOfCards = 0;

    // ensures only two arguments are entered and gives user feedback if they don't have the right inputs.
    if (argc != 2) {
        printf("%s <NUMBER_OF_CARDS_REQUIRED>\n", argv[0]);
        return -1;
    }

    if (!isCardNumberValid(argv[1], &initialNumberOfCards)) {
        printf("Invalid number of rounds\n");
        return -1;
    }

    if (!calculateRounds(initialNumberOfCards, &initialRounds)) {
        printf("error: get_number_of_rounds, run out of memory or overflow of variable rounds\n");
        return -1;
    }

    printf("number of cards: %lu, rounds: %lu\n", initialNumberOfCards, initialRounds);

    return 0;
}