#ifndef card_h
#define card_h

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./type.h"

//#define DEBUG_INFOS

card_t *newCard(unsigned long cardNumber);
bool addNewCard(list_t *list, unsigned int cardNumber);
bool initializeCards(list_t *handList, unsigned long numberOfCards);
bool isCardNumberValid(const char *inputChar, unsigned long *numberOfCards);
#endif