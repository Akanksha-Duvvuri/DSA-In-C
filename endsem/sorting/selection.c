#include<stdio.h>

int selection(int *arr, int n){
    for(int i=0; i<n-1; i++){
        int minidx = i;

        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[minidx]){
                minidx = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[minidx];
        arr[minidx] = temp;
    }
}

int print(int *arr, int n){
     for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
}   

int main() {
    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    int n = sizeof(arr) / sizeof(arr[0]);


    selection(arr, n);
    print(arr, n);
    return 0;
}