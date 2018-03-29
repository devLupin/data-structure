/*
Object : Simple Doubly Linkedlist
Date : 18.03.13
author : Hyeontaek Lim
*/

#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedlist.h"

#pragma warning(disable:4996)

int main(void) {
	int input;
	List *head = (List *)malloc(sizeof(List));
	DlistInit(&head);

	while (1) {
		printf("Input value(-1 to quit) : ");
		scanf("%d", &input);

		if (input == -1)
			break;

		DInsert(&head, input);
	}

	DDelete(&head, 2);

	DPrint(head);
}