#include <iostream>
#include "brick.hpp"
int main(){
    int length=10;
    int* arr = new int[length];
    for(int i = 0; i<length; i++){arr[i]=length-1-i;}
    for(int i = 0; i<length; i++){
        std::cout << arr[i]  << ", ";
    }
    std::cout << "\n";
    switch(0){
        default:
        case 0: brickSort   (arr,10); break; //complete
        case 1: mergeSort   (arr,10); break;
        case 2: quickSort   (arr,10); break;
        case 3: radixSort   (arr,10); break; //WIP suhas
        case 4: bitonicSort (arr,10); break;
    }
    for(int i = 0; i<10; i++){
        std::cout << arr[i]  << ", ";
    }
    return 0;
}
