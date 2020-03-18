
void filter(int*arr,int*out,int len, int bit, int value, int* x){
    int idx=0;
    int bitPos=(1<<bit);
    for(int i=0; i<len; i++){
        //find  based on each value on (val&bitPos>=<0)
        if(((arr[i]&bitPos)&&1)==value){
            out[idx]=arr[i];
            idx++;
        }
    }
    if(value==0) *x=idx;
}


//todo this function
void prefixSum(int* arr,int len){
    int d=1;
    int out[len];
    while(d<len){
        #pragma omp parallel for
        for(int i=0;i<len; i++){
            if(i>=d) out[i]=arr[i-d];
            else out[i]=0;
        }
        #pragma omp parallel for
        for(int i=0;i<len; i++){
            arr[i]=arr[i]+out[i];
        }
        d*=2;
    }
    return;
}


void parallelFilter(int*arr,int*out,int len, int bit, int value, int* x) {
    int flag[len];
    int bitPos = (1 << bit);
    //generate flag array to pass into parallel prefix
    #pragma omp parallel for
    for (int i = 0; i < len; i++) {
        flag[i] = (((arr[i] & bitPos) && 1) == value);
    }
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
    bool sorted = false; // flag until no swaps are needed
    int currArr[n];
    for(int i=0;i<n;i++)currArr[i]=arr[i];
    for(int i = 0; i<5;i++){
        radixIter(currArr,n,i);
    }
    for(int i=0;i<n;i++)arr[i]=currArr[i];
}
