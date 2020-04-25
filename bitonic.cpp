#include "common.h"
#include <cstring>
#include <limits.h>

using namespace std;

void bitonicSort(int arr[], int n){
    omp_set_num_threads(NUM_THREADS);

    int N = 1;
    while (N < n) {
	N *= 2;
    }

    int tmp[N];
    memcpy(tmp, arr, sizeof(int) * n);
   
    for (int i = n; i < N; i++) {
	tmp[i] = INT_MAX;
    }
    
    for (int i = 2; i <= N; i *= 2) {
	for (int j = i; j > 1; j /= 2) {
	    #pragma omp parallel for schedule(static)
	    for (int k = 0; k < N; k += j) {
	    	int index = (k / i);
		bool ascending = true;
		if (index % 2 == 1) {
		    ascending = false;
		}

		for (int l = k; l < k + (j / 2); l++) {
		    if (ascending == (tmp[l] >= tmp[l + j/2])) {
			int foo = tmp[l];
			tmp[l] = tmp[l + j/2];
			tmp[l + j/2] = foo;
		    }
		}
	    }
	}
    }



    memcpy(arr, tmp, sizeof(int) * n);
}
