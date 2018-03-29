#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedlist.h"

#pragma warning(disable:4996)

void DlistInit(List ** plist)
{
	(*plist)->next = (*plist)->prev = NULL;
	(*plist)->data = 0;
}

void DInsert(List ** plist, int data)
{
	List *temp = (*plist);
	List *newNode = NULL;

	if (temp->data == 0) {
		(*plist)->data = data;
		(*plist)->next = (*plist)->prev = NULL;
	}
	else {
		newNode = (List *)malloc(sizeof(List));
		newNode->data = data;

		while (temp->next != NULL) {
			temp = temp->next;
		}
		newNode->prev = temp;
		newNode->next = NULL;
		temp->next = newNode;
	}
}

void DDelete(List ** plist, int data)
{
	List *temp = (*plist);

	if (temp->data == data) {
		temp->next->prev = NULL;
		(*plist) = temp->next;
		free(temp);

		return;
	}

	while (temp->data != data)
		temp = temp->next;

	if (temp == NULL)
		return;

	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;

	free(temp);

	return;
}

void DPrint(List * plist)
{
	if (plist == NULL)
		return;
	
	while (plist != NULL) {
		printf("%d ", plist->data);
		plist = plist->next;
	}
}
