#include <iostream>
#include <ctime>
#include <omp.h>
#include <fstream>

#define NUM_THREADS 8

void brickSort(int arr[], int n);
void quickSort(int arr[], int n);
void mergeSort(int arr[], int n);
void radixSort(int arr[], int n);
void bitonicSort(int arr[], int n);
