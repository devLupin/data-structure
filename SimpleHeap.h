#ifndef __SIMPLEHEAP_H___
#define __SIMPLEHEAP_H___

#define TRUE	1
#define FALSE	0

#define HEAP_LEN	100

typedef struct _heapElem {
	int pr;
	char data;
}HeapElem;

typedef struct _heap {
	int numOfData;
	HeapElem heapArr[HEAP_LEN];
}Heap;

void HeapInit(Heap *ph);
int HIsEmpty(Heap *ph);

void HInsert(Heap *ph, char data, int pr);
char HDelete(Heap *ph);

#endif // !__SIMPLEHEAP_H___
