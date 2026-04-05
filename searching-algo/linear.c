#include<stdio.h>
//TC - O(n) as it goes one by one - last or doesnt exist. BEST CASE - O(1) - found in the first index
int linear(int *arr, int n, int key) {
    for(int i=0; i<n; i++) {
        if(arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[7] = {2, 5, 1, 10, 39, 0, 92};
    int n = sizeof(arr) / sizeof(int);
    
    printf("%d\n", linear(arr, 7, 10));
    return 0;
}