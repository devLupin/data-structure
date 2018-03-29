/*
	List Based Queue
	Author : Hyuntaek Lim
	Object : Simple List based Queue Enqueue, dequeue, print
*/

#ifndef __LB_CIRCULAR_QUEUE_H___
#define __LB_CIRCULAR_QUEUE_H___

#include "Linkedlist.h"

typedef List Node;

typedef struct listBasedQueue {
	Node *front;
	Node *rear;
}LB_Queue;

typedef LB_Queue Queue;


/* Queue is empty? */
int QIsEmpty(Queue *pq);
/* Queue Initialized */
void QueueInit(Queue *pq);
/* Queue Insert */
void Enqueue(Queue *pq, int data);
/* Queue Delete */
int Dequeue(Queue *pq);

#endif // !__LB_CIRCULAR_QUEUE_H___
