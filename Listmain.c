#include <stdio.h>
#include <stdlib.h>
#include "Linkedlist.h"

#pragma warning(disable:4996)

int main(void) {
	int input = 0;

	List *vRoot = (List *)malloc(sizeof(List));
	List *head = NULL;
	
	listInit(&vRoot);
	head = vRoot;

	while (1) {
		printf("Input value : ");
		scanf("%d", &input);

		if (input < 0)
			break;

		Insert(&head, input);
	}

	Delete(&head, 1);

	print(head);
}