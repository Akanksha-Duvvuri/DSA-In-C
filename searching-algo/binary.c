#include<stdio.h>
//TC - O(logn) very good TC ignore constants

int binary(int *arr, int start, int end, int key) {
    while(start <= end) {
        int mid = start + (end - start) / 2;
        if(arr[mid] == key) {
            return mid;
        } else if(arr[mid] > key) { //search left half
            end = mid - 1;
        } else { //search right half
            start = mid + 1;
        }
    }
    return -1;
}

int main() {
    int arr[7] = {2, 4, 6, 8, 10, 12, 14};
    int n = sizeof(arr) / sizeof(int);

    printf("%d\n", binary(arr, 0, n - 1, 10));
    return 0;
}