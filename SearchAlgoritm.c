#include <stdio.h>
#include <stdlib.h>

/* ÀÌºĞÅ½»ö */
int BinarySearch(int arr[], int search, int left, int right) {
	int mid = (left + right) / 2;
	
	if (left >= right)
		return -1;

	if (arr[mid] == search)
		return mid;
	else if (arr[mid] < search) {
		left = mid + 1;
		BinarySearch(arr, search, left, right);
	}
	else {
		right = mid - 1;
		BinarySearch(arr, search, left, right);
	}
}