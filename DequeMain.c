#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

#pragma warning(disable:4996)

int main(void) {
	int input;
	int opt;
	Deque *dq = (Deque *)malloc(sizeof(Deque));
	DequeInit(dq);

	while (TRUE) {
		printf("Input data(-1 to quit) : ");
		scanf("%d", &input);

		if (input == -1)
			break;

		printf("Input option (1.AddFirst 2.AddLast) : ");
		scanf("%d", &opt);

		switch (opt)
		{
		case 1:
			DQAddFirst(dq, input);
			break;
		case 2: 
			DQAddLast(dq, input);
			break;
		default:
			fprintf(stderr, "not efficient option \n");
			continue;
		}
	}
	printf("\n\n");

	while (!DQIsEmpty(dq)) {
		int pData = -1;

		printf("Input delete option(1.RemoveFirst 2.RemoveLast)");
		scanf("%d", &opt);

		switch (opt)
		{
		case 1:
			pData = DQRemoveFirst(dq);
			break;
		case 2:
			pData = DQRemoveLast(dq);
			break;
		default:
			fprintf(stderr, "not efficient option \n");
			pData = -1;
			continue;
		}
		if (pData != -1)
			printf("%d \n", pData);
	}

	free(dq);

	return 0;
}