#include <stdlib.h>
#include <stdio.h>
#include "Deque.h"

void DequeInit(Deque * pdeq)
{
	pdeq->head = pdeq->tail = NULL;
}

int DQIsEmpty(Deque * pdeq)
{
	if (pdeq->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void DQAddFirst(Deque * pdeq, int data)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = pdeq->head;

	if (DQIsEmpty(pdeq))
		pdeq->tail = newNode;
	else
		pdeq->head->prev = newNode;

	newNode->prev = NULL;
	pdeq->head = newNode;
}

void DQAddLast(Deque * pdeq, int data)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;

	newNode->prev = pdeq->tail;

	if (DQIsEmpty(pdeq))
		pdeq->head = newNode;
	else
		pdeq->tail->next = newNode;
	
	newNode->next = NULL;
	pdeq->tail = newNode;
}

int DQRemoveFirst(Deque * pdeq)
{
	Node *delNode = pdeq->head;
	int rData;

	if (DQIsEmpty(pdeq)) {
		fprintf(stderr, "Deque is empty");
		exit(EXIT_FAILURE);
	}
	rData = pdeq->head->data;

	pdeq->head = pdeq->head->next;
	free(delNode);

	if (pdeq->head == NULL)
		pdeq->tail = NULL;
	else
		pdeq->head->prev = NULL;

	return rData;
}

int DQRemoveLast(Deque * pdeq)
{
	Node *delNode = pdeq->tail;
	int rData;

	if (DQIsEmpty(pdeq)) {
		fprintf(stderr, "Deque is empty");
		exit(EXIT_FAILURE);
	}
	rData = pdeq->tail->data;
	
	pdeq->tail = pdeq->tail->prev;
	free(delNode);

	if (pdeq->tail == NULL)
		pdeq->head = NULL;
	else
		pdeq->tail->next = NULL;

	return rData;
}

int DQGetFirst(Deque * pdeq)
{
	if (DQIsEmpty(pdeq)) {
		fprintf(stderr, "Deque is empty");
		exit(EXIT_FAILURE);
	}

	return pdeq->head->data;
}

int DQGetLast(Deque * pdeq)
{
	if (DQIsEmpty(pdeq)) {
		fprintf(stderr, "Deque is empty");
		exit(EXIT_FAILURE);
	}

	return pdeq->tail->data;
}
