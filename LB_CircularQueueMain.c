#include <stdio.h>
#include <stdlib.h>
#include "LB_CircularQueue.h"

#pragma warning(disable:4996)

int main(void) {
	int data;

	Queue *que = (Queue *)malloc(sizeof(Queue));
	QueueInit(que);

	while (TRUE) {
		printf("Input data(-1 to quit) : ");
		scanf("%d", &data);

		if (data == -1)
			break;

		Enqueue(que, data);
	}

	printf("QueueList and Dequeue \n");
	while (!QIsEmpty(que)) {
		printf("%d ", Dequeue(que));
	}
	printf("\n");

	return 0;
}