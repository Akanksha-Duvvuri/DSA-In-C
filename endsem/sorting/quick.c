#include<stdio.h>

void print(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}

int partition(int *arr, int start, int end){

    int idx = start - 1;
    int pivot = arr[end];

    for(int j=start; j< end; j++){
        if(arr[j] <= pivot){

            idx++;

            int temp = arr[j];
            arr[j] = arr[idx];
            arr[idx] = temp;
        }
    }

    idx++;

    int temp = arr[end];
    arr[end] = arr[idx];
    arr[idx] = temp;

    return idx;
}

void quick(int *arr, int start, int end){
    if(start < end){

        int pivotIdx = partition(arr, start, end);

        quick(arr, start, pivotIdx-1);
        quick(arr, pivotIdx+1, end);
    }
}

int main(){
    int arr[6] = {12, 31, 35, 8, 32, 17};
    int n = sizeof(arr) / sizeof(int);

    quick(arr, 0, n - 1);
    print(arr, n);

    return 0;
}