#include<stdio.h>


void print(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}

void insertion(int *arr, int n){
    for(int i=0; i<n; i++){
        int curr = arr[i];
        int prev = i - 1;

        while(prev >= 0 && arr[prev] > curr){
            arr[prev + 1] = arr[prev];
            prev--;
        }

        arr[prev+1] = curr;
    }

     print(arr, n);
}

int main(){
    int arr[6] = {20, 3, 15, 2, 11, 50};
    int n = sizeof(arr) / sizeof(int);

    insertion(arr, n);

    return 0;
}
    