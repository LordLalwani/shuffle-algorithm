#include "../header-files/rounds.h"

/*
 * removes the first card from the list and returns it
 */
static card_t *remove_front(list_t *l) {
    card_t *front = l->front;

    if (l->front) {
        l->front = l->front->next;
    }

    return front;
}

/*
 * inserts a new card at the beginning of the list
 */
static void insert_front(list_t *l, card_t *c) {
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
static void insert_back(list_t *l, card_t *c) {
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
static void print(list_t *l) {
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
static bool is_sorted(list_t *hand, int number_of_cards) {
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
 * runs one round of the card shuffling algorithm
 */
static void next_round(list_t *hand, list_t *table) {
    card_t *top_card = NULL;

    while (hand->front) {  // check if cards are available
        top_card = NULL;

        // Take the top card off the hand and set it on the table
        top_card = remove_front(hand);
        insert_front(table, top_card);
        // no cards on table
        if (!top_card) {
            break;
        }

        // Take the next card off the top and put it on the bottom of the hand in your hand
        top_card = remove_front(hand);
        // no cards in hand
        if (!top_card) {
            break;
        }
        insert_back(hand, top_card);
    }
}

/*
 * picks up all cards from the card from the table and assigns it to hand
 */
static void pickup_hand(list_t **hand, list_t **table) {
    list_t *tmp = *hand;
    *hand = *table;
    *table = tmp;
}

/*
 * determines how many rounds it will take to put a deck back into the original order
 */
bool get_number_of_rounds(unsigned long number_of_cards, unsigned long *rounds) {
    if (number_of_cards <= 2) {
        *rounds = number_of_cards;
        return true;
    }

    // define hand and table (both are a list of cards)
    list_t *hand = NULL;
    list_t *table = NULL;

    // allocate memory for hand and table
    // initialize hand
    if (!init_lists(&hand, &table, number_of_cards)) {
        return false;
    }

    bool is_equal = false;
    bool is_overflow = false;

    do {
        (*rounds)++;
        next_round(hand, table);
        pickup_hand(&hand, &table);

#ifdef DEBUG_INFOS
        print(hand);
#endif

        is_equal = is_sorted(hand, number_of_cards);

        // check for an overflow of rounds
        if (*rounds == ULONG_MAX && !is_equal) {
            is_overflow = true;
            break;
        }
    } while (!is_equal);

    delete_list(&hand);
    delete_list(&table);

    if (is_overflow) {
        return false;
    }

    return true;
}