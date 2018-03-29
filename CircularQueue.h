#ifndef __CIRCULAR_QUEUE_H___
#define __CIRCULAR_QUEUE_H___

#define TRUE	1
#define FALSE	0

#define QUE_LEN		100

typedef struct _queue {
	int front;
	int rear;
	int queArray[QUE_LEN];
} Queue;


/* Queue is empty? */
int QIsEmpty(Queue *pq);
/* Queue Initialized */
void QueueInit(Queue *pq);
/* Queue Insert */
void Enqueue(Queue *pq, int data);
/* Queue Delete */
int Dequeue(Queue *pq);

#endif // !__CIRCULAR_QUEUE_H___
