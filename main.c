#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Trie.h"





int main(int argc, char *argv[]) {
	node* root = newNode(0);
	char* str = (char*)malloc(sizeof(char));
	
	insertText(root,str);
	
	if(argc == 1){
		printTrie(root, str);
	}
	
	else if(argc > 1 && *(argv[1]) == 'r'){
		printTrie_Reverse(root, str);
	}
	
	else{
        printf("bad input\n");
        exit(1);
    }
	free(str);
	free(root);
	return 0;
}