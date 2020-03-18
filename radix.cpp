#include <cstdint>

void filter(int64_t*arr, int64_t*out, int64_t len, int64_t bit, int64_t value, int64_t* x){
    int64_t idx=0;
    int64_t bitPos=(1<<bit);
    for(int64_t i=0; i<len; i++){
        if(((arr[i]&bitPos)&&1)==value){
            out[idx]=arr[i];
            idx++;
        }
    }
    if(value==0) *x=idx;
}

void prefixSum(int64_t* arr,int64_t len){
    //midterm one q4 referenced
    int64_t d=1;
    int64_t out[len];
    while(d<len){
        #pragma omp parallel for
        for(int64_t i=0;i<len; i++){
            if(i>=d) out[i]=arr[i-d];
            else out[i]=0;
        }
        #pragma omp parallel for
        for(int64_t i=0;i<len; i++){
            arr[i]=arr[i]+out[i];
        }
        d*=2;
    }
}

void parallelFilter(int64_t*arr,int64_t*out,int64_t len, int64_t bit, int64_t value, int64_t* x) {
    int64_t flag[len];
    int64_t bitPos = (1 << bit);
    //generate flag array to pass into parallel prefix
    #pragma omp parallel for //todo segfaults here for 2^n where n>17
    for (int64_t i = 0; i < len; i++) {
        flag[i] = (((arr[i] & bitPos) && 1) == value);
    }
    prefixSum(flag, len);
    if (flag[0] == 1) out[0] = arr[0];
    #pragma omp parallel for
    for (int64_t i = 1; i < len; i++) {
        if (flag[i] != flag[i - 1]) out[flag[i]-1] = arr[i];
    }
    if(value==0) *x=flag[len-1];
}
void merge(int64_t* out, int64_t* a,int64_t* b,int64_t lenA, int64_t lenB){
    #pragma omp parallel for
    for(int64_t i = 0; i<lenA+lenB; i++){
        if(i<lenA) out[i]=a[i];
        else out[i]=b[i-lenA];
    }
}

void radixIter(int64_t* arr, int64_t len, int64_t  bit){
    int64_t x=0;
    int64_t low[len];
    int64_t high[len];
    parallelFilter(arr,low,len,bit,0, &x);
    parallelFilter(arr,high,len,bit,1, &x);
    merge(arr, low,high,x,len-x);
}

void radixSort(int64_t arr[], int64_t n){
    bool sorted = false; // flag until no swaps are needed
    for(int64_t i = 0; i<64;i++){
        radixIter(arr,n,i);
    }
}
