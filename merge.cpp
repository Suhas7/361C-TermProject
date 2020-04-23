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

    int left_offset = arr_index - left_index;
    int right_offset = arr_index - right_index;

    for (int i = left_index; i < num_left; i++) {
	arr[left_offset + i] = left_array[i];
    }
    for (int i = right_index; i < num_right; i++) {
	arr[right_offset + i] = right_array[i];
    }
}

void mergeSort(int arr[], int n){
    omp_set_num_threads(NUM_THREADS);

    for (int size = 1; size < n; size *= 2) {
#pragma omp parallel for
	for (int left = 0; left < n-1; left += size * 2) {
	    int mid = min (left + size - 1, n-1);
	    int end = min (left + 2 * size - 1, n-1);
	    merge(arr, left, mid, end);
	}
    }
}

