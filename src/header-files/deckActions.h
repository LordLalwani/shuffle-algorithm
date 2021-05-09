#ifndef deckActions_h
#define deckActions_h

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "./type.h"

//#define DEBUG_INFOS

card_t *remove_front(list_t *l);
void insert_front(list_t *l, card_t *c);
void insert_back(list_t *l, card_t *c);
void print(list_t *l);
bool is_sorted(list_t *hand, int number_of_cards);
void pickup_hand(list_t **hand, list_t **table);

#endif