#include "common.h"

using namespace std;

int main(){
    /*int length = 1;
    int iterations=17;
    int factor=2;
    for(int i = 0; i<iterations; i++) {
        int arr[length];
        #pragma omp parallel for
        for (int i = 0; i < length; i++) { arr[i] = length - 1 - i; }
        clock_t time_req = clock();
        switch (1) {
            default:
            case 0: brickSort   (arr, length); break; //complete
            case 1: radixSort   (arr, length); break; //WIP, complexity is too high? some sort of overflow after 2^17
            case 2: mergeSort   (arr, length); break;
            case 3: quickSort   (arr, length); break;
            case 4: bitonicSort (arr, length); break;
        }
        std::cout <<(float) (clock()-time_req)/CLOCKS_PER_SEC << "\n";
        for (int i = 0; i < length; i++) {
            if(arr[i]!=i)
                std::cout << "fucc\n";
        }
        length*=factor;
    }*/

    cout << "Made it";
    return 0;
}
