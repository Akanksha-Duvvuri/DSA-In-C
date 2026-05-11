#include<stdio.h>

int linearSearch(int *arr, int n, int key){
    int flag = 0;

    for(int i=0; i<n; i++){
        if(arr[i] == key){
            flag = 1;
            return i;
        }
    }

    if(flag == 0) return -1;
}

int main(){
    int arr[6] = {1, 4, 3, 9, 10};
    int n = sizeof(arr) / sizeof(int);

    int result = linearSearch(arr, n, 9);

    if(result == -1){
        printf("element not found");
    } else {
        printf("element found at index %d", result);
    }

    return 0;
}