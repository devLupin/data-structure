#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"

/* select Queue next index */
int NextPosIdx(int pos) {
	if (pos == QUE_LEN - 1)
		return 0;
	else
		return pos + 1;
}

/* Is queue empty? */
int QIsEmpty(Queue *pq) {
	if (pq->front == pq->rear)
		return TRUE;
	else
		return FALSE;
}

/* queue initialized */
void QueueInit(Queue * pq)
{
	pq->front = 0;
	pq->rear = 0;
}

/* data insert */
void Enqueue(Queue * pq, int data)
{
	if (NextPosIdx(pq->rear) == pq->front) {
		fprintf(stderr, "Queue is Full");
		exit(EXIT_FAILURE);
	}

	pq->rear = NextPosIdx(pq->rear);
	pq->queArray[pq->rear] = data;
}

/* data delete */
int Dequeue(Queue * pq)
{
	if (NextPosIdx(pq->front) == pq->front) {
		fprintf(stderr, "Queue is empty");
		exit(EXIT_FAILURE);
	}

	pq->front = NextPosIdx(pq->front);
	return pq->queArray[pq->front];
}
