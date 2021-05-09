all: builder
OBJS = main.o rounds.o dataStructure.o card.o deckActions.o
CC = gcc
DEBUG = -g
CFLAGS = -Wall -O3 -c -std=c11
LFLAGS = -Wall $(DEBUG)

builder : $(OBJS)
	$(CC) $(OBJS) -o main $(LFLAGS)

rounds.o : src\header-files\rounds.h
	$(CC) $(CFLAGS) src\source-files\rounds.c

dataStructure.o : src\header-files\dataStructure.h
	$(CC) $(CFLAGS) src\source-files\dataStructure.c

deckActions.o : src\header-files\deckActions.h
	$(CC) $(CFLAGS) src\source-files\deckActions.c

card.o : src\header-files\card.h
	$(CC) $(CFLAGS) src\source-files\card.c

main.o : src\header-files\rounds.h
	$(CC) $(CFLAGS) src\source-files\main.c
	    
clean:
	del *.o *.exe