#include<stdio.h>
//take the element from the unsorted part and place it correctly in the sorted part





void print(int *arr, int n) {
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    int n = sizeof(arr) / sizeof(arr[0]);


    insertion(arr, n);
    print(arr, n);
    return 0;
}