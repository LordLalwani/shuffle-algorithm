#include "../header-files/dataStructure.h"

/*
 * creates an empty list with memory allocation
 */
static list_t *createList() {
    list_t *list = (list_t *)malloc(sizeof(list_t));
    list->front = NULL;
    list->back = NULL;

    return list;
}

/*
 * deletes the entire list from memory.
 */
void deleteList(list_t **list) {
    card_t *currentCard = (*list)->front;

    while (currentCard) {
        card_t *to_del = currentCard;
        currentCard = currentCard->next;
        free(to_del);
    }

    free(*list);
    *list = NULL;
}

/*
 * Allocates memory to lists and sets up cards in the hand.
 */
bool initializeLists(list_t **handList, list_t **tableList, unsigned long numberOfCards) {
    *handList = createList();
    if (*handList == NULL) {
        return false;
    }

    *tableList = createList();
    if (*tableList == NULL) {
        // cleanup already allocated memory
        deleteList(handList);
        return false;
    }

    // initialize cards for hand.
    bool is_valid = initializeCards(*handList, numberOfCards);
    if (!is_valid) {
        // cleanup already allocated memory from before
        deleteList(handList);
        deleteList(tableList);
        return false;
    }

    return true;
}