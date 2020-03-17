
//todo: this function, then radix is done
void filter(int*arr,int*out,int len, int bit, int value, int* x){
    int idx=0;
    int bitPos=(1<<bit);
    //todo use parallel prefix to do this, currently not parallelizable due to shared index
    //applies modified parallel prefix sum to find # preceding elements that meet criteria
    for(int i=0; i<len; i++){
        //find  based on each value on (val&bitPos>=<0)
        if((arr[i]&bitPos)==value){
            out[idx]=arr[i];
            idx++;
        }
    }
    if(value==0) *x=idx;
}

void merge(int* out, int* a,int* b,int lenA, int lenB){
    #pragma omp parallel for
    for(int i = 0; i<lenA+lenB; i++){
        if(i<lenA) out[i]=a[i];
        else out[i]=b[i-lenA];
    }
}

int* radixIter(int* arr, int len, int  bit){
    int x=0;
    int low[len];
    int high[len];
    filter(arr,low,len,bit,0, &x);
    filter(arr,high,len,bit,1, &x);
    merge(arr, low,high,x,len-x);
}


void radixSort(int arr[], int n){
    bool sorted = false; // flag until no swaps are needed
    int currArr[n];
    for(int i=0;i<n;i++)currArr[i]=arr[i];
    for(int i = 0; i<30;i++){
        radixIter(currArr,n,i);
    }
    for(int i=0;i<n;i++)arr[i]=currArr[i];
}
