#include<stdio.h>

int binarySearch(int *arr, int start, int end, int key){
    while(start <= end){
        int mid = start + (end-start) / 2;

        if(arr[mid] == key){
            return mid;
        } else if(arr[mid] > key){
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return -1;
}

int main(){
    int arr[6] = {1, 3, 4, 9, 10};
    int n = sizeof(arr) / sizeof(int);

    printf("%d", binarySearch(arr, 0, n-1, 9));
    return 0;
}