#include <stdio.h>
#include <stdlib.h>
#include "LB_CircularQueue.h"

/* Is queue empty? */
int QIsEmpty(Queue *pq) {
	if (pq->front == NULL)
		return TRUE;
	else
		return FALSE;
}

/* queue initialized */
void QueueInit(Queue * pq)
{
	pq->front = NULL;
	pq->rear = NULL;
}

/* data insert */
void Enqueue(Queue * pq, int data)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->data = data;

	if (QIsEmpty(pq)) {
		pq->rear = pq->front = newNode;
	}
	else {
		pq->rear->next = newNode;
		pq->rear = newNode;
	}
}

/* data delete */
int Dequeue(Queue * pq)
{
	Node *delNode = NULL;
	int rData;

	if (QIsEmpty(pq)) {
		fprintf(stderr, "Queue is empty");
		exit(EXIT_FAILURE);
	}

	delNode = pq->front;
	rData = delNode->data;
	pq->front = pq->front->next;

	free(delNode);

	return rData;
}
