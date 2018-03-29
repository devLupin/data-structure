#include <stdio.h>
#include <stdlib.h>
#include "ListBasedStack.h"

void SInit(Stack * sp)
{
	sp->next = NULL;
	top = 0;
}

void Spush(Stack ** sp, int data)
{
	Stack *temp = (*sp);
	Stack *newStack = NULL;

	if (top == 0) {				//스택에 처음 저장되는 경우
		temp->data = data;
		top++;

		return;
	}
	else {				// 스택에 여러번 저장된 경우
		newStack = (Stack *)malloc(sizeof(Stack));

		while (temp->next != NULL) {		//데이터의 해당 삽입위치를 찾고
			temp = temp->next;
		}
		newStack->data = data;				//값을 이어준다.
		newStack->next = NULL;
		temp->next = newStack;

		top++;				// 데이터 추가 수

		return;
	}
}

int Spop(Stack ** sp)
{
	int rData;			// Pop을 했을 경우 팝한 데이터를 반환한다.
	Stack *temp = (*sp); 
	Stack *prev = NULL;

	if (top == 0) {			//스택에 아무것도 없는 경우
		fprintf(stderr, "Stack is empty");
		exit(EXIT_FAILURE);
	}

	while (temp->next != NULL) {		//LIFO 구조에 맞게 마지막 원소 위치를 찾음.
		prev = temp;
		temp = temp->next;
	}
	rData = temp->data;
	prev->next = NULL;
	free(temp);				//메모리 해제 해주고

	top--;		//개수 하나 줄여주고

	return rData;		//해당 데이터 반환.
}

void stackPrint(Stack * sp)
{
	printf("numOfStack : %d \n", top);
	printf("Stack List : ");
	while (sp != NULL) {		//스택의 마지막 데이터까지 출력
		printf("%d ", sp->data);
		sp = sp->next;
	}
	printf("\n\n");
}
