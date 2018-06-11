#include "UsefulHeap.h"

/* Heap의 초기화 */
void HeapInit(Heap * ph, PriorityComp pc)
{
	ph->numOfData = 0;		//힙의 저장된 개수
	ph->comp = pc;
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
	if (GetLChildIdx(idx) > idx)
		return 0;

	else if (GetLChildIdx(idx) == idx)
		return GetLChildIdx(idx);

	else {
		if (ph->comp(ph->heapArr[GetLChildIdx(idx)],
			ph->heapArr[getRChildIdx(idx)]) < 0)
			return getRChildIdx(idx);
		else
			return GetLChildIdx(idx);
	}
}

void HInsert(Heap * ph, char data)
{
	int idx = ph->numOfData + 1;

	while (idx != 1) {
		if (ph->comp(data, ph->heapArr[GetParentIdx(idx)]) > 0) {
			ph->heapArr[idx] = ph->heapArr[GetParentIdx(idx)];
			idx = GetParentIdx(idx);
		}
		else
			break;
	}

	ph->heapArr[idx] = data;
	ph->numOfData++;
}

char HDelete(Heap * ph)
{
	char retData = ph->heapArr[1];
	char lastElem = ph->heapArr[ph->numOfData];

	int parentIdx = 1;
	int childIdx;

	while (childIdx = GetHiPriChildIdx(ph, parentIdx)) {
		if (ph->comp(lastElem, ph->heapArr[childIdx]) >= 0)
			break;

		ph->heapArr[parentIdx] = ph->heapArr[childIdx];
		parentIdx = childIdx;
	}

	ph->heapArr[parentIdx] = lastElem;
	ph->numOfData--;

	return retData;
}
