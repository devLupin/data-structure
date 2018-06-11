#include <stdio.h>
#include <stdlib.h>

/*
	버블 정렬
	시간 복잡도 : O(n^2)
*/
void BubbleSort(int arr[], int sz) {
	int i, j;
	int temp;

	for (i = 0; i < sz - 1; i++) {
		for (j = i + 1; j < sz; j++) {
			if (arr[i] < arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}


/*
	삽입 정렬
	시간 복잡도 : O((n^2)/2)
*/
void InsertionSort(int arr[], int sz) {
	int i, j;
	int insData;

	for (i = 1; i < sz; i++) {
		insData = arr[i];

		for (j = i - 1; j >= 0; j--) {
			if (arr[j] > insData)
				arr[j + 1] = arr[j];
			else
				break;
		}

		arr[j + 1] = insData;
	}
}




/*나눈 배열을 정렬한다.*/
void MergeTwoArea(int arr[], int left, int mid, int right) {
	int fIdx = left;
	int rIdx = mid + 1;
	int i;
	
	int *sortArr = (int *)malloc(sizeof(int)*(right+1));
	int sIdx = left;

	while (fIdx <= mid && rIdx <= right) {
		if (arr[fIdx] <= arr[rIdx])
			sortArr[sIdx] = arr[fIdx++];
		else
			sortArr[sIdx] = arr[rIdx++];

		sIdx++;
	}

	if (fIdx > mid) {
		for (i = rIdx; i <= right; i++, sIdx++)
			sortArr[sIdx] = arr[i];
	}
	else {
		for (i = fIdx; i <= mid; i++, sIdx++)
			sortArr[sIdx] = arr[i];
	}

	for (i = left; i < right; i++)
		arr[i] = sortArr[i];;

	free(sortArr);
}
void MergeSort(int arr[], int left, int right) {	//분할
	int mid = (left + right) / 2;
	
	if (left < right) {
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);
		MergeTwoArea(arr, left, mid, right);
	}
} 




void Swap(int arr[], int idx1, int idx2) {
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}
int Partition(int arr[], int left, int right) {
	int pivot = arr[left];
	int low = left + 1;
	int high = right;

	while (low <= high) {
		while (pivot > arr[low] && low <= right)
			low++;
		while (pivot < arr[high] && high >= (left + 1))
			high--;

		if (low <= high)
			Swap(arr, low, high);
	}

	Swap(arr, left, high);
	return high;
}
void QuickSort(int arr[], int left, int right) {
	if (left <= right) {
		int pivot = Partition(arr, left, right);

		QuickSort(arr, left, pivot);
		QuickSort(arr, pivot + 1, right);
	}
}