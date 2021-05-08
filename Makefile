all: rounds
OBJS = main.o rounds.o
CC = gcc
DEBUG = -g
CFLAGS = -Wall -O3 -c -std=c11
LFLAGS = -Wall $(DEBUG)

rounds : $(OBJS)
	$(CC) $(OBJS) -o rounds $(LFLAGS)

rounds.o : src\header-files\rounds.h
	$(CC) $(CFLAGS) src\source-files\rounds.c

main.o : src\header-files\rounds.h
	$(CC) $(CFLAGS) src\source-files\main.c
	    
clean:
	del *.o