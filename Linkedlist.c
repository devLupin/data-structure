#include <stdio.h>
#include <stdlib.h>
#include "Linkedlist.h"

/* list의 초기화 */
void listInit(List ** plist)
{
	(*plist)->next = NULL;
}

/* list의 삽입 왼쪽에서 오른쪽 순으로 */
void Insert(List ** head, int data)
{
	List *newNode = (List *)malloc(sizeof(List)); //새로운 노드 생성
	List *temp = *head;		//임시노드 생성. 값의 탐색을 위함

	if (temp->data < 0) {	// 처음 리스트에 값을 저장할 때
		temp->data = data;
		
		newNode->next = NULL;
		temp->next = newNode;
	}
	else {			// 처음 이후 리스트에 값을 저장할 때
		newNode->next = NULL;		//새로운 노드의 다음 노드는 존재x
		
		while (temp->next != NULL) {	// 빈자리를 찾는다.
			temp = temp->next;
		}
		temp->data = data;		// 데이터와 다음 노드를 지정
		temp->next = newNode;
	}
}

void Delete(List ** head, int data)
{
	List *temp = *head;			//임시노드
	List *prev = NULL;			//이전 노드

	/* 첫번째 노드 삭제 시 */
	if (temp != NULL && temp->data == data) { 
		(*head) = (*head)->next;	//루트를 그 다음 노드로 설정
		free(temp);					//처음 루트노드 삭제

		return;
	}

	/* 해당 데이터의 위치를 찾는다. */
	while (temp != NULL && temp->data != data) {
		prev = temp;
		temp = temp->next;
	}

	/* 끝까지 찾아도 없다면 */
	if (temp == NULL)
		return;

	/* 1. 삭제 하려는 노드의 이전 노드의 다음 노드를 삭제하려던 노드의 다음 노드로 설정 */
	prev->next = temp->next;
	free(temp);

	return;
}

void print(List * head)
{
	while (head->next != NULL) {
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}
