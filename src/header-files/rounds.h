#ifndef rounds_h
#define rounds_h

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "./dataStructure.h"
#include "./deckActions.h"

bool calculateRounds(unsigned long number_of_cards, unsigned long *rounds);

#endif