#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

list* newList() {
    list *l = malloc(sizeof(list));
	if(!l)
		return NULL;
	l->head = l->tail = NULL;
	l->length = 0;
    return l;
}

void traverse(list *l) {
	node *ptr = l->head;
	while(ptr) {
		printf("%p\n", ptr->element);
		ptr = ptr->next;
	}
}

node* create(void *element) {
	node *tmp = malloc(sizeof(node));
	if(!tmp)
		return NULL;

	tmp->element = element;
	tmp->next = NULL;
	return tmp;
}

void append(list *l, void *element) {
	node *tmp = create(element);
	if(!tmp)
		return;
	
	if(l->tail)
		l->tail->next = tmp;	
	else 
		l->head = tmp;
	l->tail = tmp;
	l->length++;
}
/**
 * pos denotes the the position str will have in l
 * 0 indicates first position and last is length-1 (considering that length has increased by 1 after insertion)
 */
void insert(list *l, void *element, int pos) {
	if(pos >= l->length) {
		append(l, element);
		return;
	}
	node *new = create(element);
	if(!new)
		return;
		
	if(pos <= 0) {
		new->next = l->head;
		l->head = new;
		l->length++;
		return;
	}
	node *ptr = l->head;
	while(--pos)
		ptr = ptr->next;
	//insert new after ptr
	node *tmp = ptr->next;
	ptr->next =  new;
	new->next = tmp;
	l->length++;
}

void* remov(list *l, int pos) {
	if(pos < 0 || pos > l->length-1)
		return NULL;
	if(pos == 0) {
		node *toremove = l->head;
		l->head = l->head->next;
		if(!l->head)
			l->tail = NULL;
		void *toreturn = toremove->element;
		free(toremove);
		l->length--;
		return toreturn;
	}
	node *removenext = l->head;
	while(--pos)
		removenext = removenext->next;
		
	node *toremove = removenext->next;
	removenext->next = toremove->next;
	char *toreturn = toremove->element;
	free(toremove);
	l->length--;
	if(removenext->next == NULL)
		l->tail = removenext;
	return toreturn;
}

int length(list *l) {
	return l->length;
}

void reverse(list *l) {
	if(l->length < 2)
		return;
	node *sublist = l->head->next;
	node *reversed = l->head;
	while(sublist) {
		node *current = sublist;
		sublist = sublist->next;
		current->next = reversed;
		reversed = current;
	}
	l->head->next = NULL;
	l->tail = l->head;
	l->head = reversed;
}

