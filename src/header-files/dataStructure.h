#ifndef dataStructure_h
#define dataStructure_h

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

//#define DEBUG_INFOS

typedef struct card {
    unsigned int long number;
    struct card_t *next;
} card_t;

typedef struct list {
    card_t *front;
    card_t *back;
} list_t;

bool init_lists(list_t **hand, list_t **table, unsigned long number_of_cards);

void delete_list(list_t **l);

#endif