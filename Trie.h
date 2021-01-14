#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define NUM_LETTERS 26

typedef struct node {
	char letter;
	long unsigned int count;
	struct node* children[NUM_LETTERS];
}node;

node* newNode(char c);
addstring(node* root, char* str);
printTrie(node* root, char* str);
printTrie_Reverse(node* root, char* str);
void insertText(node* root, char* str);

