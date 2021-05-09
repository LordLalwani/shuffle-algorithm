#ifndef deckActions_h
#define deckActions_h

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "./type.h"

// #define DEBUG_INFOS

card_t *removeFront(list_t *l);
void insertFront(list_t *l, card_t *c);
void insertBack(list_t *l, card_t *c);
void print(list_t *l);
bool isHandSorted(list_t *hand, int number_of_cards);
void pickupHand(list_t **hand, list_t **table);

#endif