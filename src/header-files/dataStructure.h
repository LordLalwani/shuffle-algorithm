#ifndef dataStructure_h
#define dataStructure_h

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "./card.h"
#include "./type.h"

//#define DEBUG_INFOS

bool initializeLists(list_t **handList, list_t **tableList, unsigned long numberOfCards);
void deleteList(list_t **list);

#endif