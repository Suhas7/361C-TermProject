
//todo: splits array into 2 based on bit
int* filter(int*arr,int bit, int value, int* x){
    int length=0;

    if(value==0) *x=length;
}

int* merge(int* a,int* b,int lenA, int lenB){
    int* out = new int[lenA+lenB];
    for(int i = 0; i<lenA+lenB; i++){
        if(i<lenA) out[i]=a[i];
        else out[i]=b[i-lenA];
    }
    delete a;
    delete b;
    return out;
}

int* radixIter(int* arr, int len, int  bit){
    int x=0;
    int* low = filter(arr,bit,0, &x);
    int* high = filter(arr,bit,1, &x);
    return merge(low,high,x,len);
}


void radixSort(int arr[], int n){
    bool sorted = false; // flag until no swaps are needed
    int* currArr=new int[n];
    for(int i=0;i<n;i++)currArr[i]=arr[i];
    for(int i = 0; i<30;i++){
        int* last=currArr;
        currArr=radixIter(arr,n,i);
        delete last;
    }
    for(int i=0;i<n;i++)arr[i]=currArr[i];
    delete currArr;
}
