#include "../header-files/deckActions.h"

/*
 * removes the first card from the list and returns it
 */
card_t *remove_front(list_t *l) {
    card_t *front = l->front;

    if (l->front) {
        l->front = l->front->next;
    }

    return front;
}

/*
 * inserts a new card at the beginning of the list
 */
void insert_front(list_t *l, card_t *c) {
    c->next = NULL;

    if (l->front == NULL) {
        l->front = c;
        l->back = c;
    } else {
        c->next = l->front;
        l->front = c;
    }
}

/*
 * inserts a new card at the end of the list
 */
void insert_back(list_t *l, card_t *c) {
    c->next = NULL;

    if (l->front == NULL) {
        l->front = c;
        l->back = c;
    } else {
        l->back->next = c;
        l->back = c;
    }
}

/*
 * prints the complete list of cards
 */
void print(list_t *l) {
    card_t *curr = l->front;

    printf("hand: ");
    while (curr != NULL) {
        printf("%lu ", curr->number);
        curr = curr->next;
    }
    printf("\n");
}

/*
 * checks if the list is sorted by increasing numbers
 */
bool is_sorted(list_t *hand, int number_of_cards) {
    unsigned long curr_number = 0;
    card_t *curr = hand->front;

    for (curr_number = 0; curr_number < number_of_cards; curr_number++) {
        if (curr->number != curr_number) {
            return false;
        }

        curr = curr->next;
    }

    return true;
}

/*
 * picks up all cards from the card from the table and assigns it to hand
 */
void pickup_hand(list_t **hand, list_t **table) {
    list_t *tmp = *hand;
    *hand = *table;
    *table = tmp;
}
