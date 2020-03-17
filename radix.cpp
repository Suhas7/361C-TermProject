int* filter(int*arr,int bit, int value){

}

int* merge(int* a,int* b,int lenA, int lenB){
    int* out = new int[lenA+lenB];
    for(int i = 0; i<lenA+lenB; i++){
        if(i<lenA) out[i]=a[i];
        else out[i]=b[i-lenA];
    }
    delete a;
    delete b;
    return out
}

int* radixIter(int* arr, int len, int  bit){
    int x=0;
    int* low = filter(arr,bit,0);
    int* high = filter(arr,bit,1);
    return merge(low,high,,len);
}

void radixSort(int arr[], int n){
    bool sorted = false; // flag until no swaps are needed
    for(int i = 0; i<30;i++){
        int* last=arr;
        arr=radixIter(arr,n,i);
        delete last;
    }
}
