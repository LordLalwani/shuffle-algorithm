#include "../header-files/dataStructure.h"

/*
 * allocates an empty list  
 */
static list_t *create_empty_list() {
    list_t *l = (list_t *)malloc(sizeof(list_t));
    l->front = NULL;
    l->back = NULL;

    return l;
}

/*
 * deallocates the entire list
 */
void delete_list(list_t **l) {
    card_t *curr = (*l)->front;

    while (curr) {
        card_t *to_del = curr;
        curr = curr->next;
        free(to_del);
    }

    free(*l);
    *l = NULL;
}

/*
 * allocated memory for hand and table and initializes the hand
 */
bool init_lists(list_t **hand, list_t **table, unsigned long number_of_cards) {
    // allocate memory for hand
    *hand = create_empty_list();
    if (*hand == NULL) {
        return false;  // return false if memory allocation for hand fails
    }

    // allocate memory for table
    *table = create_empty_list();
    if (*table == NULL) {
        delete_list(hand);  // cleanup already allocated memory from before
        return false;       // return false if memory allocation for table fails
    }

    // initialize cards for hand
    bool is_valid = init_cards(*hand, number_of_cards);
    if (!is_valid) {
        delete_list(hand);   // cleanup already allocated memory from before
        delete_list(table);  // cleanup already allocated memory from before
        return false;
    }

    return true;
}