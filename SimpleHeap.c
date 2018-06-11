#include "SimpleHeap.h"

void HeapInit(Heap * ph)
{
	ph->numOfData = 0;
}

int HIsEmpty(Heap * ph)
{
	if (ph->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}

int GetParentIdx(int idx) {
	return idx / 2;
}
int GetLChildIdx(int idx) {
	return idx * 2;
}
int getRChildIdx(int idx) {
	return GetLChildIdx(idx) + 1;
}

int GetHiPriChildIdx(Heap *ph, int idx) {
	if (GetLChildIdx(idx) > ph->numOfData)
		return 0;
	else if (GetLChildIdx(idx) == ph->numOfData)
		return GetLChildIdx(idx);
	else {
		if (ph->heapArr[GetLChildIdx(idx)].pr >
			ph->heapArr[getRChildIdx(idx)].pr])
			return getRChildIdx(idx);
		else
			return GetLChildIdx(idx);
	}
}

void HInsert(Heap * ph, char data, int pr)
{
	int idx = ph->numOfData + 1;
	HeapElem lelem = { pr, data };

	while (idx != 1) {
		if (pr < ph->heapArr[GetParentIdx(idx)].pr) {
			ph->heapArr[idx] = ph->heapArr[GetParentIdx(idx)];
			idx = GetParentIdx(idx);
		}
		else
			break;
	}

	ph->heapArr[idx] = lelem;
	ph->numOfData++;
}

char HDelete(Heap * ph)
{
	char retData = (ph->heapArr[1]).data;
	HeapElem lastElem = ph->heapArr[ph->numOfData];

	int parentIdx = 1;
	int childIdx;

	while (childIdx = GetHiPriChildIdx(ph, parentIdx)) {
		if (lastElem.pr <= ph->heapArr[childIdx].pr)
			break;

		ph->heapArr[parentIdx] = ph->heapArr[childIdx];
		parentIdx = childIdx;
	}

	ph->heapArr[parentIdx] = lastElem;
	ph->numOfData--;

	return retData;
}
