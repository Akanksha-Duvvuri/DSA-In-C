#include<stdio.h>
//try to get the smallest element and put it at the beginning of the array
//TC - O(n^2)


void selection(int *arr, int n) {
    for(int i=0; i<n-1; i++) {
        int minIdx = i;
        for(int j=1+i; j<n; j++) {
            if(arr[j] < arr[minIdx]) {
                minIdx = j;  //say you found 11, that becomes your minimum index now. Now swap that with the i value
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }
}

void print(int *arr, int n) {
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