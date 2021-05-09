#ifndef card_h
#define card_h

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "./type.h"

//#define DEBUG_INFOS

card_t *newCard(unsigned long number);
bool addNewCard(list_t *l, unsigned int number);
bool initializeCards(list_t *hand, unsigned long numberOfCards);
#endif