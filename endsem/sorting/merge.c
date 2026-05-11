#include<stdio.h>

void print(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}

void merge(int *arr, int start, int mid, int end){
    int size = end - start + 1;
    int tempArr[size];

    int i = start, j = mid + 1, k = 0;

    while(i <= mid && j <= end){
        if(arr[i] <= arr[j]){
            tempArr[k++] = arr[i++];
        } else {
            tempArr[k++] = arr[j++];
        }
    }

    while(i <= mid) {
        tempArr[k++] = arr[i++];
    }


    while(j <= end) {
        tempArr[k++] = arr[j++];
    }

    for(int p= 0; p< size; p++){
        arr[start + p] = tempArr[p];
    }
}

void mergeSort(int *arr, int start, int end){
    if(start <= end){
        int mid = start + (end -start)/2;

        mergeSort(arr, start, mid-1);
        mergeSort(arr, mid+1, end);

        merge(arr, start, mid, end);
        
    }
}

int main(){
    int arr[6] = {12, 31, 35, 8, 32, 17};
    int n = sizeof(arr) / sizeof(int);

    mergeSort(arr, 0, n - 1);
    print(arr, n);

    return 0;
}