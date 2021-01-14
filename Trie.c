#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Trie.h"





void insertText(node* root, char* str){
	int i = 0;
	while (1){
		char c = getchar();
		if (c == EOF) break;
		if (isspace(c) || c == EOF) {
			str = realloc(str, i + 1);
			str[i] = 0;
			addstring(root, str);
			i = 0;

			if (c == EOF) break;
		}
		else if (isalpha(c)) {
			c = tolower(c);
			str = realloc(str, i + 1);
			str[i] = c;
			i++;
		}
	}
}

node* newNode(char c) {
	struct node* n;
	if (n = (node*)malloc(sizeof(node))) {
		n->letter = c;
		n->count = 0;
		for (int j = 0; j < NUM_LETTERS; j++) {
			n->children[j] = NULL;
		}
	}
	return n;
}

addstring(node* root, char* str) {
	int i = 0;
	char temp;
	int index;

	while (*str) {
		temp = tolower(*str);
		index = temp - 'a';
		if (root->children[index] == NULL) {
			root->children[index] = newNode(temp);
			if (*str == EOF || *str == '\0') {
				root->count += 1;
			}
		}
		else {
			root = root->children[index];
			str++;
			if (*str == EOF || *str == '\0') {
				root->count += 1;
			}
		}
		
	}

}

printTrie(node* root,char* str) {
	static int i = 0;
	//static int j = 1;
	if(root->letter != '\0' && root->letter != NULL) {
			str[i] = root->letter;
			i++;
		}
	if(*str != NULL && root->count > 0) {
		str[i] = '\0';
		printf("%s %ld\n", str, root->count);
		root->count = 0;
	}
	for (int k = 0; k < NUM_LETTERS; k++) {
		if (root->children[k] != NULL) {
			printTrie(root->children[k], str);
		}
		if (i > 0 && k==25) {
				str[i - 1] = '\0';
				i--;
			}
	}
}

printTrie_Reverse(node* root, char* str) {
	static int u = 0;
	if (root->letter != '\0' && root->letter != NULL) {
		str[u] = root->letter;
		u++;
	}
	if (*str != NULL && root->count > 0) {
		str[u] = '\0';
		printf("%s %ld\n", str, root->count);
		root->count = 0;
	}
	for (int k = NUM_LETTERS-1; k >= 0; k--) {
		if (root->children[k] != NULL) {
			printTrie_Reverse(root->children[k], str);
		}
		if (u > 0 && k == 1) {
			str[u - 1] = '\0';
			u--;
		}
	}
}