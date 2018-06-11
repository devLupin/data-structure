#ifndef __USEFUL_HEAP_H___
#define __USEFUL_HEAP_H___

#define TRUE	1
#define FALSE	0

#define HEAP_LEN	100

typedef int PriorityComp(int data1, int data2);

typedef struct _heap {
	PriorityComp *comp;
	int numOfData;
	char heapArr[HEAP_LEN];
}Heap;

void HeapInit(Heap *ph, PriorityComp pc); 
int HIsEmpty(Heap *ph);

void HInsert(Heap *ph, char data);
char HDelete(Heap *ph);

#endif // !__USEFUL_HEAP_H___
