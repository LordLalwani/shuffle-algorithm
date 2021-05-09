#include "../header-files/rounds.h"

/*
 * runs one round of the card shuffling algorithm
 */
static void nextRound(list_t *handList, list_t *tableList) {
    card_t *topCard = NULL;

    // check if cards are available
    while (handList->front) {
        topCard = NULL;

        // Take the top card off the hand and set it on the table
        topCard = removeFront(handList);
        insertFront(tableList, topCard);
        // no cards on table
        if (!topCard) {
            break;
        }

        // Take the next card off the top and put it on the bottom of the hand in your hand
        topCard = removeFront(handList);
        // no cards in hand
        if (!topCard) {
            break;
        }
        insertBack(handList, topCard);
    }
}

/*
 * calculates how many rounds we require to get the deck back into the original state.
 */
bool calculateRounds(unsigned long numberOfCards, unsigned long *rounds) {
    list_t *handList = NULL;
    list_t *tableList = NULL;

    if (numberOfCards <= 2) {
        *rounds = numberOfCards;
        return true;
    }

    if (!initializeLists(&handList, &tableList, numberOfCards)) {
        return false;
    }

    bool isEqual = false;
    bool isOverflow = false;

    do {
        (*rounds)++;
        nextRound(handList, tableList);
        pickupHand(&handList, &tableList);

#ifdef DEBUG_INFOS
        print(handList);
#endif

        isEqual = isHandSorted(handList, numberOfCards);

        // check for an overflow of rounds
        if (*rounds == ULONG_MAX && !isEqual) {
            isOverflow = true;
            break;
        }
    } while (!isEqual);

    deleteList(&handList);
    deleteList(&tableList);

    if (isOverflow) {
        return false;
    }

    return true;
}