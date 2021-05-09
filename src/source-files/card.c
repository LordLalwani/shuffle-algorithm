#include "../header-files/card.h"

/*
 * creates a new card node
 */
card_t *new_card(unsigned long number) {
    card_t *node = (card_t *)malloc(sizeof(card_t));

    // error checking
    if (node != NULL) {
        node->number = number;
        node->next = NULL;
    }

    return node;
}

/*
 * inserts a new card at the end of the list
 */
bool add_new_card(list_t *l, unsigned int number) {
    card_t *c = new_card(number);

    // error checking
    if (c == NULL) {
        return false;
    }

    if (l->front == NULL) {
        l->front = c;
        l->back = c;
    } else {
        l->back->next = c;
        l->back = c;
    }

    return true;
}

bool init_cards(list_t *hand, unsigned long number_of_cards) {
    unsigned long i = 0;
    bool is_valid = true;

    for (i = 0; i < number_of_cards; i++) {
        is_valid = add_new_card(hand, i);

        if (!is_valid) {
            return false;
        }
    }

    return true;
}