#include "history.h"
#include <stdlib.h>
#include <stdio.h>
List * init_history(){
	List * linkedlist = (List*) malloc(sizeof(List));
	linkedlist -> root = NULL;
	return linkedlist;
	
}
//Helped by michael contraras  
void add_history(List * list, char * str){
	Item * new_node =(Item*) malloc(sizeof(Item)) ;
	Item * temp = (Item*)malloc(sizeof(Item));
	int length;
	char * copy;

	for(length = 0; str[length] != '\0'; length++)
		;
	
	copy = (char*) malloc(length+1);

	for(length = 0; str[length] != '\0'; length++)
		copy[length] = str[length];
	

	if(list -> root == NULL){
		list ->root = new_node;
		new_node -> str = copy;//
		new_node -> next = NULL;//

	}else{
	Item * current = list -> root;
	 int count = 1;
		for(;current -> next  != NULL; current = current -> next){
			count++;
		}
		current -> next = temp;
		temp -> id = count;
		temp -> str = copy;
		temp ->  next = NULL;
		
	}
	
}

char * get_history(List * list, int id){
	Item * current = list -> root; 

	for(; current -> id < id; current = current -> next){

	}

	return current -> str;
}

void print_history(List *list){

	for(Item * current = list -> root; current != NULL; current = current -> next){
		printf("%d : %s\n", current -> id, current -> str);
	}
}


void free_history(List * list){
	Item * current;
	Item * next;

	current = list -> root;
	while(current){
		current = next;
		next = current -> next;
		free(current);
		

	}
}

