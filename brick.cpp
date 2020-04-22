#include "common.h"

void brickSort(int arr[], int n){
    omp_set_num_threads(NUM_THREADS);

    bool sorted = false; // flag until no swaps are needed
    while (!sorted){
        sorted = true;
#pragma omp parallel for //across all even elem pairs
        for (int i=0; i<=n-2; i+=2){ //for each even pair
            if (arr[i] > arr[i+1]){ //swap if needed
                int x=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=x;
                sorted = false; //mark flag to denote unclean iteration
            }
        }
#pragma omp parallel for //across all odd elem pairs
        for (int i=1; i<=n-2; i+=2){
            if (arr[i] > arr[i+1]){ //swap if needed
                int x=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=x;
                sorted = false; //mark flag to denote unclean iteration
            }
        }
    }
}
