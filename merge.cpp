#include "common.h"

int min (int x, int y) {
    return (x < y) ? x : y;
}

void merge(int arr[], int left, int mid, int right) {
//merge the two halves of the array

    int num_left = mid - left + 1;
    int num_right = right - mid;
    int left_array[num_left];
    int right_array[num_right];

    for (int i = left; i <= mid; i++) {
	left_array[i - left] = arr[i];
    }
    for (int i = mid + 1; i <= right; i++) {
	right_array[i - mid - 1] = arr[i];
    }
    
    int left_index = 0;
    int right_index = 0;
    int arr_index = left;

    while (left_index < num_left && right_index < num_right) {
	if (left_array[left_index] <= right_array[right_index]) {
	    arr[arr_index] = left_array[left_index];
	    left_index++;
	}
	else {
	    arr[arr_index] = right_array[right_index];
	    right_index++;
	}
	arr_index++;
    }

    while (left_index < num_left) {
	arr[arr_index] = left_array[left_index];
	arr_index++;
	left_index++;
    }
    while (right_index < num_right) {
	arr[arr_index] = right_array[right_index];
	arr_index++;
	right_index++;
    }
}

void mergeSort(int arr[], int n){
    for (int size = 1; size < n; size *= 2) {

	for (int left = 0; left < n-1; left += size * 2) {
	    int mid = min (left + size - 1, n-1);
	    int end = min (left + 2 * size - 1, n-1);

	    merge(arr, left, mid, end);
	}
    }
}
