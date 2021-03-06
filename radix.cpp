#include "common.h"

using namespace std;

void prefixSum(int* arr, int len){
    int out[len];
    for (int d = 1; d < len; d *= 2) {
	#pragma omp parallel for
        for(int i = 0; i < len; i++){
            if(i >= d) {
		out[i] = arr[i-d];
	    }
            else {
		out[i] = 0;
	    }
        }
	#pragma omp parallel for
        for(int i = 0; i < len; i++){
            arr[i] += out[i];
	}
    }
}

void parallelFilter(int*arr,int*out,int len, int bit, int value, int* x) {
    int flag[len];
    int bitPos = (1 << bit);
    
    #pragma omp parallel for
    for (int i = 0; i < len; i++) {
        flag[i] = (((arr[i] & bitPos) && 1) == value);
    }
    #pragma omp critical
    prefixSum(flag, len);
    if (flag[0] == 1) out[0] = arr[0];

    #pragma omp parallel for
    for (int i = 1; i < len; i++) {
        if (flag[i] != flag[i - 1]) out[flag[i]-1] = arr[i];
    }
    if(value==0) *x=flag[len-1];
}

void merge(int* out, int* a,int* b,int lenA, int lenB){
    #pragma omp parallel for
    for(int i = 0; i<lenA+lenB; i++){
        if(i<lenA) out[i]=a[i];
        else out[i]=b[i-lenA];

    }
}

void radixIter(int* arr, int len, int  bit){
    int x=0;
    int low[len];
    int high[len];
    parallelFilter(arr,low,len,bit,0, &x);
    parallelFilter(arr,high,len,bit,1, &x);
    merge(arr, low,high,x,len-x);
}

void radixSort(int arr[], int n){
    omp_set_num_threads(NUM_THREADS);

    for(int i = 0; i < 32;i++){
        radixIter(arr,n,i);
    }
}
