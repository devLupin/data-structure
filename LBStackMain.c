/*
	Simple List Based Stack
	author : Hyuntaek Lim
	Object : Stack Push & Pop
*/

#include <stdlib.h>
#include <stdio.h>
#include "ListBasedStack.h"

#pragma warning(disable:4996)

int main(void) {
	int data;
	int deleteData;

	Stack *head = (Stack *)malloc(sizeof(Stack));
	SInit(head);

	while (TRUE) {
		printf("Input stack data(-1 to quit) :");
		scanf("%d", &data);

		if (data == -1)
			break;

		Spush(&head, data);
		stackPrint(head);
	}

	deleteData = Spop(&head);
	stackPrint(head);

	return 0;
}