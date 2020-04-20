#include <iostream>
#include <openmp.h>
#include <ctime>
#include <cstdint>
#include <openmp.h>

void brickSort(int arr[], int n);
void quickSort(int arr[], int n);
void mergeSort(int arr[], int n);
void radixSort(int arr[], int n);
void bitonicSort(int arr[], int n);
void writeToFile(char name[], int arr[], int n);
