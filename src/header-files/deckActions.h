#ifndef deckActions_h
#define deckActions_h

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "./type.h"

// #define DEBUG_INFOS

card_t *removeFront(list_t *list);
void insertFront(list_t *list, card_t *card);
void insertBack(list_t *list, card_t *card);
void print(list_t *list);
bool isHandSorted(list_t *handList, int numberOfCards);
void pickupHand(list_t **handList, list_t **tableList);

#endif