CC=gcc
CFLAGS=-g -Wall
all: randint randdemo

randint: randint.c randint.h
	$(CC) -c randint.c

randdemo: randdemo.c randint
	$(CC) $(CFLAGS) randdemo.c randint.o -o randdemo
