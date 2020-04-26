#include "common.h"
#include <sstream>
#include <string>
#include "common.h"
#include <string.h>
#include <stdio.h>
#include <cstdlib>

using namespace std;

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1; 
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;  
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void recurse(int arr[], int low, int high)
{
    if (low < high)
    {
        //place elements according to pivot
        int pi = partition(arr, low, high);
        //create tasks for each partition of array. Serialise if smaller than 1024 elements to reduce overhead
#pragma omp task firstprivate(arr,low,pi) if (pi - low > 1024)
        {
            recurse(arr, low, pi - 1);
        }
#pragma omp task firstprivate(arr,high,pi) if (high - pi > 1024)
        {
            recurse(arr, pi + 1, high);
        }
    }
}

//Quick sort algorithm using OpenMP
//adapted from https://www.geeksforgeeks.org/cpp-program-for-quicksort/

void quickSort(int arr[], int n) {
    //set number of threads to use
    omp_set_num_threads(NUM_THREADS);
    //encase all in parallel sharing array and n
#pragma omp parallel shared(arr,n)
    {
        //one thread launches recursion
#pragma omp single nowait
        {
            int low = 0;
            int high = n - 1;
            recurse(arr, low, high);
        }
    }
}
