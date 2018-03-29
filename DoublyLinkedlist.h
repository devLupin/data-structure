/*
	Object : Simple Doubly Linkedlist
	Date : 18.03.13
	author : Hyeontaek Lim
*/

#ifndef _DLINKEDLIST_H___
#define _DLINKEDLIST_H___

#define TRUE	1
#define FALSE	0

typedef struct _DLinkedlist {
	int data;
	struct _DLinkedlist *prev;
	struct _DLinkedlist *next;
} DList;

typedef DList List;

void DlistInit(List **plist);

void DInsert(List **plist, int data);

void DDelete(List **plist, int data);

void DPrint(List *plist);

#endif // !_DLINKEDLIST_H___
