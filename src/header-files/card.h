#ifndef card_h
#define card_h

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "./type.h"

//#define DEBUG_INFOS

card_t *new_card(unsigned long number);
bool add_new_card(list_t *l, unsigned int number);
bool init_cards(list_t *hand, unsigned long number_of_cards);
#endif