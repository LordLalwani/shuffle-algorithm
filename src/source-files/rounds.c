#include "../header-files/rounds.h"

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