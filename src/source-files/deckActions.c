#include "../header-files/deckActions.h"

/*
 * removes the first card from the list and returns it
 */
card_t *removeFront(list_t *list) {
    card_t *front = list->front;

    if (list->front) {
        list->front = list->front->next;
    }

    return front;
}

/*
 * inserts a new card at the beginning of the list
 */
void insertFront(list_t *list, card_t *card) {
    card->next = NULL;

    if (list->front == NULL) {
        list->front = card;
        list->back = card;
    } else {
        card->next = list->front;
        list->front = card;
    }
}

/*
 * inserts a new card at the end of the list
 */
void insertBack(list_t *list, card_t *card) {
    card->next = NULL;

    if (list->front == NULL) {
        list->front = card;
        list->back = card;
    } else {
        list->back->next = card;
        list->back = card;
    }
}

/*
 * prints the complete list of cards
 */
void print(list_t *l) {
    card_t *currentCard = l->front;

    printf("hand: ");
    while (currentCard != NULL) {
        printf("%lu ", currentCard->number);
        currentCard = currentCard->next;
    }
    printf("\n");
}

/*
 * checks if the list is sorted by increasing numbers
 */
bool isHandSorted(list_t *handList, int numberOfCards) {
    unsigned long currentNumber = 0;
    card_t *currentCard = handList->front;

    for (currentNumber = 0; currentNumber < numberOfCards; currentNumber++) {
        if (currentCard->number != currentNumber) {
            return false;
        }

        currentCard = currentCard->next;
    }

    return true;
}

/*
 * picks up all cards from the card from the table and assigns it to hand
 */
void pickupHand(list_t **handList, list_t **tableList) {
    list_t *tmp = *handList;
    *handList = *tableList;
    *tableList = tmp;
}
