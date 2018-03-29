#ifndef __DEQUE_H___
#define __DEQUE_H___

#include "DoublyLinkedlist.h"

typedef List Node;

typedef struct _deque {
	Node *head;
	Node *tail;
	int data;
} Deque;

void DequeInit(Deque *pdeq);

int DQIsEmpty(Deque *pdeq);

/* 덱의 머리에 데이터를 저장한다. */
void DQAddFirst(Deque *pdeq, int data);

/* 덱의 꼬리에 데이터를 저장한다. */
void DQAddLast(Deque *pdeq, int data);

/* 덱의 머리에 위치한 데이터를 반환 및 소멸 */
int DQRemoveFirst(Deque *pdeq);

/* 덱의 꼬리에 위치한 데이터를 반환 및 소멸 */
int DQRemoveLast(Deque *pdeq);

/* 덱의 머리에 위치한 데이터를 소멸하지 않고 반환 */
int DQGetFirst(Deque *pdeq);

/* 덱의 꼬리에 위치한 데이터를 소멸하지 않고 반환 */
int DQGetLast(Deque *pdeq);


#endif // !__DEQUE_H___
