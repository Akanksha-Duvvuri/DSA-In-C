#include<stdio.h>

int bubbleSort(int *arr, int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    return -1;
}

void printArr(int *arr, int n){
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}

int main() {
    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    int n = sizeof(arr) / sizeof(int);

    bubbleSort(arr, n);
    printArr(arr, n);

    return 0;
}
