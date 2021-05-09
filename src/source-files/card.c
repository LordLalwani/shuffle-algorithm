#include "../header-files/card.h"

/*
 * Builds a new card node
 */
card_t *newCard(unsigned long cardNumber) {
    card_t *node = (card_t *)malloc(sizeof(card_t));

    // error checking
    if (node != NULL) {
        node->number = cardNumber;
        node->next = NULL;
    }

    return node;
}

/*
 * inserts a new card at the end of the list.
 */
bool addNewCard(list_t *handList, unsigned int cardNumber) {
    card_t *c = newCard(cardNumber);

    // error checking
    if (c == NULL) {
        return false;
    }

    if (handList->front == NULL) {
        handList->front = c;
        handList->back = c;
    } else {
        handList->back->next = c;
        handList->back = c;
    }

    return true;
}

/*
 * initializes cards and assigns them to a hand list.
 */
bool initializeCards(list_t *handList, unsigned long numberOfCards) {
    unsigned long i = 0;
    bool isValid = true;

    for (i = 0; i < numberOfCards; i++) {
        isValid = addNewCard(handList, i);

        if (!isValid) {
            return false;
        }
    }

    return true;
}