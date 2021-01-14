  
CC = gcc
FLAGS = -Wall -g

all: frequency

frequency: main.o Trie.o
	$(CC) $(FLAGS) -o frequency main.o Trie.o

main.o: main.c Trie.h
	$(CC) $(FLAGS) -c main.c 

trie.o: Trie.c Trie.h
	$(CC) $(FLAGS) -c Trie.c 

.PHONY: clean all

clean:
	rm -f *.o frequency