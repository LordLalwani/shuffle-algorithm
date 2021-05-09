#ifndef dataStructure_h
#define dataStructure_h

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "./card.h"
#include "./type.h"

//#define DEBUG_INFOS

bool initializeLists(list_t **hand, list_t **table, unsigned long number_of_cards);
void deleteList(list_t **l);

#endif