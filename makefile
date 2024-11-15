CC = gcc
CFLAGS = -c -Wall
SRC = src
TEST = test

all: vector.o heap.o
	$(CC) vector.o heap.o -o main

vector.o:
	$(CC) $(CFLAGS) $(SRC)/vector.c

heap.o: vector.o
	$(CC) $(CFLAGS) $(SRC)/heap.c vector.o

test: vector.o
	$(CC) $(TEST)/check_vector.c vector.o -lcheck -lm -lpthread -lrt -o check_vector_tests

# TODO debug the test compilation with https://www.khoury.northeastern.edu/home/skotthe/classes/cs5600/fall/2015/labs/intro-check.html

clean:
	-rm main *.o

.PHONY: all clean
