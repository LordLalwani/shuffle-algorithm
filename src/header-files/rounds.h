#ifndef rounds_h
#define rounds_h

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "./card.h"
#include "./dataStructure.h"
#include "./deckActions.h"

bool calculateRounds(unsigned long numberOfCards, unsigned long *rounds);

#endif